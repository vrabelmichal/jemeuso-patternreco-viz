// $Id: EReader.cc 2922 2011-06-12 14:21:23Z mabl $
// Author: ale   2005/06/22

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EReader                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// EReader
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "EReader.hh"
#include "EEvent.hh"
#include <TList.h>
#include <TMap.h>
#include <TFile.h>
#include <TObjString.h>
#include <TChain.h>
#include <TSystem.h>
#include <TRegexp.h>

ClassImp(EReader)

//_____________________________________________________________________________
EReader::EReader() : fEvTree(0), fEvent(0) {
    //
    // Constructor
    //

    fFiles = new TList;
    fFiles->SetOwner();
    fBaseNames = new TList;
    fBaseNames->SetOwner();
    fFriendsExt = new TMap;
    fFriendsExt->SetOwner();
}

//_____________________________________________________________________________
EReader::~EReader() {
    //
    // Destructor
    //

    Clear();
    delete fFiles;
    delete fBaseNames;
    delete fFriendsExt;
}

//______________________________________________________________________________
void EReader::Clear(Option_t* opt) {
    //
    //
    //

    SafeDelete(fEvent);

    if ( fEvTree && fEvTree->TestBit(kCanDelete) )
        delete fEvTree;
            

    fFiles->Delete();
    fBaseNames->Delete(); 
    fFriendsExt->Delete();
}

//______________________________________________________________________________
TList* EReader::DirFileList(const char *name) {
    //
    // Taken from TChain::Add
    //
    
    TList* l = new TList;
    l->SetOwner();

    // case with one single file
    if (!TString(name).MaybeWildcard()) {
        l->Add(new TObjString(name));
        return l;
    }

    // wildcarding used in name
    TString basename(name);

    Int_t slashpos = basename.Last('/');
    TString directory;
    if (slashpos>=0) {
        directory = basename(0,slashpos); // Copy the directory name
        basename.Remove(0,slashpos+1);      // and remove it from basename
    } else {
        directory = gSystem->WorkingDirectory();
    }

    const char *file;
    gSystem->ExpandPathName(directory);
    void *dir = gSystem->OpenDirectory(directory);

    if (dir) {
        //create a TList to store the file names (not yet sorted)
        TRegexp re(basename,kTRUE);
        while ((file = gSystem->GetDirEntry(dir))) {
            if (!strcmp(file,".") || !strcmp(file,"..")) continue;
            TString s = file;
            if ( (basename!=file) && s.Index(re) == kNPOS) continue;
            l->Add(new TObjString(directory+"/"+file));
        }
        gSystem->FreeDirectory(dir);
        //sort the files in alphanumeric order
        l->Sort();
    }
    return l;
}

//______________________________________________________________________________
Int_t EReader::Open( const char* files ) {
    //
    // Open files and creates the chain. If possible creates also the img chain
    // and links it to the tree
    //
    
    TList* l = DirFileList(files);

    TString ext = ".root";

    TIter next(l);
    // parse the file list
    while(TObjString* str = (TObjString*)next()) {

        TString s = str->GetString();
        gSystem->ExpandPathName(s);
        
        // skip all not std rootfiles
        if ( !s.EndsWith(ext) ) continue;
        
        TString basename = s(0,s.Sizeof()-ext.Sizeof());
        
        TIter nextExt(fFriendsExt);
        Bool_t skip = kFALSE;
        while(TObjString* extName = (TObjString*)nextExt()) {
            TString dummy = "_"+extName->GetString();
            if ( basename.EndsWith(dummy) ) {
                skip = kTRUE;
                break;
            }
        }
            
        if ( skip ) continue;

        fBaseNames->Add(new TObjString(basename));

    }
    
    delete l;
    
    TIter nextSimu(fBaseNames);

    if ( fBaseNames->GetEntries() > 1) {

        // build the chain out of the list of collected files
        TChain* chain = new TChain("etree");
        chain->SetBit(kCanDelete);

        while( TObjString* str = (TObjString*)nextSimu() )
            chain->Add(str->GetString()+ext);

        fEvTree = chain;
    } else if ( fBaseNames->GetEntries() == 1 ) {
        TObjString* str = (TObjString*)nextSimu();
        TFile *f = new TFile(str->GetString()+ext);
        fEvTree = (TTree*)f->Get("etree");

        if ( !fEvTree ) return 0;

        fFiles->Add(f);
        
    } else return 0;


    fEvent = new EEvent();
    fEvent->SetBranches(fEvTree);
    
    return fBaseNames->GetEntries();
}

//______________________________________________________________________________
void EReader::AddExt( const char* ext, const char* tname ) {
    fFriendsExt->Add(new TObjString(ext), new TObjString(tname));
}

//______________________________________________________________________________
Int_t EReader::ConnectFriends() {
    //
    // Looks for the friends tree stored in rootfiles whose name is defined by
    // fFriendsExt. If the number of friend files is equal to the number of
    // main files, a chain is assembled and connected to the main tree
    //

    // no base files, stop here
    if ( !fBaseNames->GetEntries() ) return 0;

    TString ext = ".root";
    
    TList fileNames;
    fileNames.SetOwner();

    TIter nextExt(fFriendsExt);
    Int_t nFriends(0);
    
    // loop on the extensions
    while(TObjString* strExt = (TObjString*)nextExt()) {
        TIter next(fBaseNames);

        while(TObjString* str = (TObjString*)next()) {
            // check existence of the friend files

            TString name = str->GetString()+"_"
                +strExt->GetString()+ext;
            if ( gSystem->AccessPathName(name) ) {
                Info("ConnectFriends","%s not found", (const char*) name);
                break;
            }

            fileNames.Add(new TObjString(name));

        }

        if ( fileNames.GetEntries() == fBaseNames->GetEntries() ) {
            TIter nextFriend(&fileNames);
            TString tname = ((TObjString*)fFriendsExt->GetValue(strExt))->GetString();
            if ( fileNames.GetEntries() == 1 ) {
                // 1 file, create only a tree
                TObjString* str = (TObjString*)nextFriend();
                TFile *f = new TFile(str->GetString());
                TTree *t = (TTree*)f->Get(tname);
                if ( t ) {
                    fEvTree->AddFriend(t);
                    nFriends++;
                } else 
                    Printf("File or Tree not found: file %s, tree %s",f->GetName(), tname.Data());
            } else {
                // build the chain
                TChain* chain = new TChain(tname);
                // CHECK:                    chain->SetBit(kCanDelete);

                while(TObjString* str = (TObjString*)nextFriend()){
                    chain->Add(str->GetName());
                }

                chain->GetEntries();
                fEvTree->AddFriend(chain);
                nFriends++;
            }
        }

    }

    // force the chain (if one) to connect the trees
    fEvTree->GetEntries();
    return nFriends;
}
