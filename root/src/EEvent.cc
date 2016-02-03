// $Id: EEvent.cc 2918 2011-06-10 22:22:31Z mabl $
// Author: M. Pallavicini , 12 2002

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EEvent                                                               *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/

#include "EEvent.hh"
#include "Etypes.hh"

#include "ETruth.hh"
#include "EHeader.hh"
#include "EGeometry.hh"
#include "EDetector.hh"
#include "ESimpleDetector.hh"
#include "EShower.hh"
#include "EAtmosphere.hh"
#include "EChipTrackTrigger.hh"
#include "ELblTrackTrigger.hh"
#include "ERunParameters.hh"
#include "ELTTTrigger.hh"
#include "EPTTTrigger.hh"
#include "ECCB_LTTTrigger.hh"

     ClassImp (EEvent)
     ClassImp (EEvTreeLink)
     EEvent * EEvent::fgCurrent = 0;

// class EEvent
//______________________________________________________________________________
EEvent::EEvent (Int_t branches):fTreeLink (0)
{
  //
  // Constructor
  //

  // branches
  fHeader = new EHeader ();
  fTruth = new ETruth ();
  fGeometry = new EGeometry ();

  fShower = (branches & kShower) ? new EShower () : 0;
  fAtmosphere = (branches & kAtmosphere) ? new EAtmosphere () : 0;
  fDetector = (branches & kDetector) ? new EDetector () : 0;
  fSimpleDetector = (branches & kSimpleDetector) ? new ESimpleDetector () : 0;
  fChipTrackTrigger =
    (branches & kChipTrackTrigger) ? new EChipTrackTrigger () : 0;
  fLblTrackTrigger =
    (branches & kLblTrackTrigger) ? new ELblTrackTrigger () : 0;
  fPTTTrigger = (branches & kPTTTrigger) ? new EPTTTrigger () : 0;
  fLTTTrigger = (branches & kLTTTrigger) ? new ELTTTrigger () : 0;
  fCCB_LTTTrigger = (branches & kCCB_LTTTrigger) ? new ECCB_LTTTrigger () : 0;

  // build pars
  fRunPars = new ERunParameters ();

}

//______________________________________________________________________________
EEvent::EEvent (const EEvent & other):
TObject ()
{
  // copy ctor

  other.Copy (*this);
}

//______________________________________________________________________________
EEvent::~EEvent ()
{
  // destructor

  Delete ();

  if (GetCurrent () == this)
    SetCurrent (0);

}

//______________________________________________________________________________
void EEvent::Copy (TObject & other) const {
  //
  // Copy this to other
  //

  // EEvent& event = (EEvent&)other;

  // TODO
}

//______________________________________________________________________________
Bool_t EEvent::BranchTree (TTree * t, Bool_t link)
{
  //
  // Branch tree on EEvent data members
  //

  Bool_t branched = kTRUE;

  // add capability not to branch on a subevent if requested
  // branches
  if (fHeader)
    t->Branch ("header", "EHeader", &fHeader);
  if (fTruth)
    t->Branch ("truth", "ETruth", &fTruth);
  if (fGeometry)
    t->Branch ("geometry", "EGeometry", &fGeometry);

  if (fShower)
    t->Branch ("shower", "EShower", &fShower);
  if (fAtmosphere)
    t->Branch ("atmosphere", "EAtmosphere", &fAtmosphere);
  if (fDetector)
    t->Branch ("detector", "EDetector", &fDetector);
  if (fSimpleDetector)
    t->Branch ("simpledetector", "ESimpleDetector", &fSimpleDetector);
  if (fChipTrackTrigger)
    t->Branch ("trigger", "EChipTrackTrigger", &fChipTrackTrigger);
  if (fLblTrackTrigger)
    t->Branch ("lbltrigger", "ELblTrackTrigger", &fLblTrackTrigger);
  if (fPTTTrigger)
    t->Branch ("PTT_trigger", "EPTTTrigger", &fPTTTrigger);
  if (fLTTTrigger)
    t->Branch ("LTT_trigger", "ELTTTrigger", &fLTTTrigger);
  if (fCCB_LTTTrigger)
    t->Branch ("CCB_LTTTrigger", "ECCB_LTTTrigger", &fCCB_LTTTrigger);



  // pars
  if (link)
    {
      t->GetUserInfo ()->Add (fRunPars);
      LinkTree (t);
    }
  return branched;

}

//______________________________________________________________________________
Bool_t EEvent::SetBranches (TTree * t, Bool_t clone)
{
  //
  // Sets branches addresses for reading. Returns kTRUE if any of the
  // container exists in the tree. If one of the data member is 0 and
  // corresponding branch is found, it is automatically allocated.
  // If clone is true, a clone of ERunParameters (and the other eventual data
  // stored in the etree)is created and the tree is not linked.
  //

  if (!t)
    return kFALSE;

  Delete ();

  Bool_t branched = kFALSE;

  TBranch *branch;

  // branches
  if ((branch = t->GetBranch ("header")))
    t->SetBranchAddress ("header", &fHeader);
  branched |= (branch != 0);

  if ((branch = t->GetBranch ("truth")))
    t->SetBranchAddress ("truth", &fTruth);
  branched |= (branch != 0);

  if ((branch = t->GetBranch ("geometry")))
    t->SetBranchAddress ("geometry", &fGeometry);
  branched |= (branch != 0);

  if ((branch = t->GetBranch ("shower")))
    t->SetBranchAddress ("shower", &fShower);
  branched |= (branch != 0);

  if ((branch = t->GetBranch ("atmosphere")))
    t->SetBranchAddress ("atmosphere", &fAtmosphere);
  branched |= (branch != 0);

  if ((branch = t->GetBranch ("detector")))
    t->SetBranchAddress ("detector", &fDetector);
  branched |= (branch != 0);

  if ((branch = t->GetBranch ("simpledetector")))
    t->SetBranchAddress ("simpledetector", &fSimpleDetector);
  branched |= (branch != 0);

  if ((branch = t->GetBranch ("trigger")))
    t->SetBranchAddress ("trigger", &fChipTrackTrigger);
  branched |= (branch != 0);

  if ((branch = t->GetBranch ("lbltrigger")))
    t->SetBranchAddress ("lbltrigger", &fLblTrackTrigger);
  branched |= (branch != 0);

  if ((branch = t->GetBranch ("PTT_trigger")))
    t->SetBranchAddress ("PTT_trigger", &fPTTTrigger);
  branched |= (branch != 0);

  if ((branch = t->GetBranch ("LTT_trigger")))
    t->SetBranchAddress ("LTT_trigger", &fLTTTrigger);
  branched |= (branch != 0);

  if ((branch = t->GetBranch ("CCB_LTTTrigger")))
    t->SetBranchAddress ("CCB_LTTTrigger", &fCCB_LTTTrigger);
  branched |= (branch != 0);


  // pars
  SafeDelete (fRunPars);

  // FIXME: temporary workaround for old rootfiles
  if (t->GetDirectory ())
    {
      TTree *runtree = (TTree *) t->GetDirectory ()->Get ("runtree");

      if (runtree)
	{

	  runtree->SetBranchAddress ("runpars", &fRunPars);
	  runtree->GetEntry ();
	}
    }

  // if runpars is still null, look for it in UserInfo
  if (!fRunPars)
    {
      ERunParameters *pars =
	(ERunParameters *) t->GetUserInfo ()->FindObject ("ERunParameters");
      if (pars && clone)
	fRunPars = (ERunParameters *) pars->Clone ();
      else
	{
	  fRunPars = pars;
	  LinkTree (t);
	}
    }


  return branched;

}


//______________________________________________________________________________
void EEvent::LinkTree (TTree * t)
{
  //
  //
  //

  if (!t)
    return;

  fTreeLink = (EEvTreeLink *) t->GetUserInfo ()->FindObject ("EEvTreeLink");

  if (!fTreeLink)
    {
      fTreeLink = new EEvTreeLink (t, this);
      t->GetUserInfo ()->Add (fTreeLink);
    }
  else
    fTreeLink->SetEvent (this);

}

//______________________________________________________________________________
void EEvent::UnlinkTree ()
{
  //
  // Disconnect tree from the event. This is required before deleting the tree
  // If the tree holds ERunParameters, they are cloned and the clone is
  // stored in the tree
  //

  if (!fTreeLink)
    return;

  fTreeLink->SetEvent (0);
  // runpars are hold by the tree
  fRunPars = 0;
  // and linktree as well
  fTreeLink = 0;


//    if ( !GetTree() ) return;
//
//    TList* user = GetTree()->GetUserInfo();
//
//    Bool_t clone=kTRUE;
//    TTree *fTree = GetTree();
//    if ( user->FindObject(fRunPars) && clone ) {
//       user->Remove(fRunPars);
//       user->Add(fRunPars->Clone());
//    }
//
//    fTreeLink = 0;
//
//    if ( fTree && fRunPars && fTree->GetUserInfo()->FindObject(fRunPars) )
//        fTree->GetUserInfo()->Remove(fRunPars);
//
//    fTree = 0;
}

//______________________________________________________________________________
void EEvent::Build (Int_t run, Int_t ev, const char *name)
{
  // build header

  if (fHeader)
    {
      fHeader->SetNum (ev);
      fHeader->SetRun (run);
      fHeader->SetRunName (name);
    }
}

//______________________________________________________________________________
void EEvent::Clear (Option_t * opt)
{
  // clear event
  TString options (opt);

  // branches
  if (fHeader)
    fHeader->Clear (opt);
  if (fTruth)
    fTruth->Clear (opt);
  if (fGeometry)
    fGeometry->Clear (opt);

  if (fShower)
    fShower->Clear (opt);
  if (fAtmosphere)
    fAtmosphere->Clear (opt);
  if (fDetector)
    fDetector->Clear (opt); 
  if (fSimpleDetector)
    fSimpleDetector->Clear (opt);
  if (fChipTrackTrigger)
    fChipTrackTrigger->Clear (opt);
  if (fLblTrackTrigger)
    fLblTrackTrigger->Clear (opt);
  if (fPTTTrigger)
    fPTTTrigger->Clear (opt);
  if (fLTTTrigger)
    fLTTTrigger->Clear (opt);
  if (fCCB_LTTTrigger)
    fCCB_LTTTrigger->Clear (opt);

  // pars
//   if (fRunPars && options.Contains ("C"))
//     fRunPars->Clear ();                            //DN: do not clean it. It causes crash in EEventViewer.

//    if ( options.Contains("C") )
//         Delete();
}

//______________________________________________________________________________
void EEvent::ClearAndShrink (Option_t * opt)
{
  //
  //
  //

  Clear (opt);
  if (fShower)
    fShower->ClearAndShrink (opt);
  if (fAtmosphere)
    fAtmosphere->ClearAndShrink (opt);
  if (fDetector)
    fDetector->ClearAndShrink (opt);
  if (fSimpleDetector)
    fSimpleDetector->ClearAndShrink (opt);
}

//______________________________________________________________________________
void EEvent::Delete (Option_t *)
{
  //
  // Delete all containers
  //

  // branches
  SafeDelete (fHeader);
  SafeDelete (fTruth);
  SafeDelete (fGeometry);

  SafeDelete (fShower);
  SafeDelete (fAtmosphere);
  SafeDelete (fDetector);
  SafeDelete (fSimpleDetector);
  SafeDelete (fChipTrackTrigger);
  SafeDelete (fLblTrackTrigger);
  SafeDelete (fPTTTrigger);
  SafeDelete (fLTTTrigger);
  SafeDelete (fCCB_LTTTrigger);

  // pars
  if (IsLinked ())
    //
    // ERunParamters are owned by the tree.
    // Just forget about them
    //
    UnlinkTree ();
  else
    SafeDelete (fRunPars);

}

//______________________________________________________________________________
Bool_t EEvent::Fill (EFiller & f)
{
  //
  // Deliver filler to its target
  //

  TString target (f.GetTarget ());

  EFillable *fillable;

  if (target == "ETruth")
    {
      fillable = fTruth;
    }
  else if (target == "EGeometry")
    {
      fillable = fGeometry;
    }
  else if (target == "EShower")
    {
      fillable = fShower;
    }
  else if (target == "EAtmosphere")
    {
      fillable = fAtmosphere;
    }
  else if (target == "EDetector")
    {
      fillable = fDetector;
    }
  else if (target == "ESimpleDetector")
    {
      fillable = fSimpleDetector;
    }
  else if (target == "EChipTrackTrigger")
    {
      fillable = fChipTrackTrigger;
    }
  else if (target == "ELblTrackTrigger")
    {
      fillable = fLblTrackTrigger;
    }
  else if (target == "EPTTTrigger")
    {
      fillable = fPTTTrigger;
    }
  else if (target == "ELTTTrigger")
    {
      fillable = fLTTTrigger;
    }
  else if (target == "ECCB_LTTTrigger")
    {
      fillable = fCCB_LTTTrigger;
    }
  else
    {
      Error ("Fill", "Filler type %s unknown", target.Data ());
      return kFALSE;
    }

  // if filled is a null pointer return
  if (!fillable)
    return kFALSE;

  // try to fill the selected object
  Bool_t filled = fillable->Fill (f);

  if (!filled)
    Error ("Fill", "Unable to fill %s with filler type %s",
	   fillable->Class_Name (), target.Data ());

  return filled;

}


//______________________________________________________________________________
EEvTreeLink::EEvTreeLink ():fEvent (0)
{
  //
  // Default constructor
  //

}


//______________________________________________________________________________
EEvTreeLink::EEvTreeLink (TTree * t):fEvent (0)
{
  //
  //
  //

  fTreeRef = t;
}


//______________________________________________________________________________
EEvTreeLink::EEvTreeLink (TTree * t, EEvent * ev):fEvent (ev)
{
  //
  // Destructor
  //

  fTreeRef = t;
}

//______________________________________________________________________________
EEvTreeLink::~EEvTreeLink ()
{
  //
  // Destructor
  //

  if (fEvent)
    fEvent->UnlinkTree ();
}
