// $Id: EOpticsResponse.cc 3051 2014-01-23 12:04:57Z fenu $
// Author: ale   2005/01/19

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EOpticsResponse                                                      *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// OpticsResponse
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "EOpticsResponse.hh"
#include "EORSample.hh"
#include "EORHeader.hh"

#include <TFile.h>
#include <TTree.h>
#include <TH2F.h>
#include <TClonesArray.h>
#include <TSystem.h>
#include <stdexcept>
#include <iostream>
#include <TMath.h>
using namespace std;

ClassImp(EOpticsResponse)

//_____________________________________________________________________________
EOpticsResponse::EOpticsResponse( const char *dbname ) : 
    fFile(0), fTree(0), fSample(0), fHeader(0), fPsf(0), fPoints(0) {
    //
    // Constructor
    //


    FileStat_t buf;
    if ( gSystem->GetPathInfo(dbname, buf) != 0 ) MakeZombie();
    else {
        fFile = new TFile(dbname);
        if( !(fTree = (TTree*)fFile->Get("ORDatabase")) ) MakeZombie();
    }

    if( IsZombie() ) {
       Error("EOpticsResponse","Can not open or find the Optics DataBase.");
    
       Error("EOpticsResponse","Please run macros/tools/opticsresponse.C click Build button");
       
       return;
    }
    fHeader = (EORHeader*)fTree->GetUserInfo()->FindObject("EORHeader");

    fTree->SetBranchAddress("EORSample",&fSample);
    
    fTree->BuildIndex("EORSample.fThetaIndex","EORSample.fLambdaIndex");
       
    fPoints = new TClonesArray("TVector3",1000000);
    
    fPoints->BypassStreamer(kFALSE);
    
    Info("EOpticsResponse","Enabled. Reading from DB file: %s",fFile->GetName());
  
}

//_____________________________________________________________________________
EOpticsResponse::~EOpticsResponse() {
    //
    // Destructor
    //

    SafeDelete(fFile);
    SafeDelete(fTree);
    SafeDelete(fSample);
    SafeDelete(fPoints);
}

//_____________________________________________________________________________
Bool_t EOpticsResponse::GetEntry(Float_t theta, Float_t phi, Float_t lambda) {
    //
    // Reads the entry from the OR DB file for given theta , phi (in rad) and lambda (in nm)
    //

    if ( IsZombie() ) return kFALSE;

    Float_t ThetaStep  = ( fHeader->GetThetaMax() - fHeader->GetThetaMin() ) / fHeader->GetBinsTheta();

    Float_t PhiStep    = ( fHeader->GetPhiMax() - fHeader->GetPhiMin() ) / fHeader->GetBinsPhi();
     
    Float_t LambdaStep = ( fHeader->GetLambdaMax() - fHeader->GetLambdaMin() ) / fHeader->GetBinsLambda(); 
    
    
    Int_t IndexTheta  = Int_t(theta/ThetaStep); 
    
    Int_t IndexPhi    = Int_t((phi+TMath::Pi())/PhiStep);

    Int_t IndexLambda = Int_t((lambda-fHeader->GetLambdaMin())/LambdaStep); 
   
    if ( theta  <= fHeader->GetThetaMin()  )  IndexTheta  = fHeader->GetThetaIndexMin();
    if ( theta  >= fHeader->GetThetaMax()  )  IndexTheta  = fHeader->GetThetaIndexMax();
    if ( phi  <= fHeader->GetPhiMin()  )      IndexPhi  = fHeader->GetPhiIndexMin();
    if ( phi  >= fHeader->GetPhiMax()  )      IndexPhi  = fHeader->GetPhiIndexMax();
    if ( lambda <= fHeader->GetLambdaMin() )  IndexLambda = fHeader->GetLambdaIndexMin();
    if ( lambda >= fHeader->GetLambdaMax() )  IndexLambda = fHeader->GetLambdaIndexMax();
    
    fTree->GetEntry(IndexLambda+(fHeader->GetBinsLambda()+1)*IndexPhi+(fHeader->GetBinsLambda()+1)*(fHeader->GetBinsPhi()+1)*IndexTheta);
    //works if  loops in OpticsResponseBuilder are ordered from inner to outer as lambda, phi, theta.
    return kTRUE; 
}

//_____________________________________________________________________________
TH2F* EOpticsResponse::MakePsfHist(Float_t theta, Float_t phi, TH1F* spectrum){
    //
    // Returns a histo with weighted sum of Psf distributions for the entry spectrum
    //
    if ( IsZombie() ) return NULL;
    if( !spectrum )               return (TH2F*) NULL;
    if( !spectrum->GetEntries() ) return (TH2F*) NULL;

    Float_t lambda, weigth, weigthtot(0);
    Int_t entry(0);

    for (Int_t i = 1; i <= spectrum->GetNbinsX(); i++) {
        lambda = spectrum->GetBinCenter(i);
        weigth = spectrum->GetBinContent(i);
        if (!weigth) continue;
        weigthtot += weigth; 
        GetEntry(theta,phi,lambda);

        TH2F* htemp = GetSample()->GetPsfHist(); // TODO: CHECK if should be deleted in the end!!!

	if (!htemp) {
	    Warning("MakePsfHist(Float_t theta, Float_t phi, TH1F* spectrum)","can not find the histo");
	    return (TH2F*) NULL;
	}
        for (Int_t j=1; j<=htemp->GetNbinsX(); j++)
            for (Int_t k=1; k<=htemp->GetNbinsY(); k++) {
                if (entry > fPoints->GetEntriesFast()) break;

                Float_t x = htemp->GetXaxis()->GetBinCenter(j);
                Float_t y = htemp->GetYaxis()->GetBinCenter(k);
                Float_t z = htemp->GetBinContent(j,k);

                x = x*TMath::Cos(phi) - y*TMath::Sin(phi);
                y = x*TMath::Sin(phi) + y*TMath::Cos(phi);
                z = z*weigth;

                TClonesArray &ref = *fPoints;

                new(ref[entry++]) TVector3(x,y,z);
            } 
    }

    // define corners of the histo

    Float_t xmin(100000), xmax(-xmin), ymin(xmin), ymax(-ymin);
    for (Int_t i=0; i<entry; i++) {
        TVector3 *pos = (TVector3*)fPoints->At(i);    
	if (xmin > pos->X()) xmin = pos->X();
	if (xmax < pos->X()) xmax = pos->X();
	if (ymin > pos->Y()) ymin = pos->Y();
	if (ymax < pos->Y()) ymax = pos->Y();
    }

    Int_t nx,ny;

    nx = ny = fHeader->GetPsfBins();

    if ( fPsf ) {
        //TOCHECK: is it fast?

        fPsf->SetBins(nx, xmin, xmax, ny, ymin, ymax);
        fPsf->Reset();
    } 

    else {	

        fPsf = new TH2F("psf", "Psf for the spectrum", nx, xmin, xmax, ny, ymin, ymax);
//         fPsf->SetDirectory(0);
    }

    for (Int_t i=0; i < entry; i++) {

        TVector3 *pos = (TVector3*)fPoints->At(i);             
        fPsf->Fill(pos->X(),pos->Y(),pos->Z()/weigthtot);
    }
    return fPsf;
}

//______________________________________________________________________________
void EOpticsResponse::Clear( Option_t* ) {
    //
    // Clears all temporary histograms
    //

    SafeDelete( fPsf );
    fPoints->Clear();

}

//_____________________________________________________________________________
TH2F* EOpticsResponse::MakePsfHist(Float_t theta, Float_t phi, Float_t lambda){
    //
    // Returns Psf distribution for the given theta and phi
    //
    if ( !GetEntry(theta,phi,lambda) ) return NULL; 
    TH2F* fPsf = fSample->MakePsfHistRotated(phi);
//     fPsf->SetDirectory(0);
    
    return fPsf;
    
}
