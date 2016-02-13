// $Id: EEvent.hh 3039 2013-10-29 13:48:57Z guzman $
// Author: M. Pallavicini , 12 2002

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EEvent                                                               *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/

#ifndef __EEVENT_HH__
#define __EEVENT_HH__

#include "TObject.h"
#include "TString.h"
#include "TTree.h"
#include "TRef.h"
#include "TList.h"




#include "root/include/EFillable.hh"
#include "root/include/EPTTTrigger.hh"//guzman added them to be able to use this classes in RootInputModule
#include "root/include/ECCB_LTTTrigger.hh"//guzman
class ETruth;
class EHeader;
class EGeometry;
class EDetector;
class ESimpleDetector;
class EShower;
class EAtmosphere;
class EChipTrackTrigger;
class ELblTrackTrigger;
class ERunParameters;
class EEvent;
class EPTTTrigger;
class ELTTTrigger;
class ECCB_LTTTrigger;

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EEvTreeLink                                                                //
//                                                                            //
// Link between tree and the event. Its aim is to control the objects shared  //
// between the event and the ree, like ERunParameters. An EEvTreeLink is      //
// added to TTree::fUserInfo when the tree is attached to the EEvent via      //
// EEvent::SetBranches. EEvTreeLink notifies the deletion of the tree and     //
// automatically removes the linking.                                         //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

class EEvTreeLink:public TObject
{
public:
  EEvTreeLink ();
  EEvTreeLink (TTree *);
  EEvTreeLink (TTree *, EEvent *);
  virtual ~ EEvTreeLink ();

  TTree *GetTree () const
  {
    return (TTree *) fTreeRef.GetObject ();
  }
  EEvent *GetEvent () const
  {
    return fEvent;
  }
  void SetEvent (EEvent * e)
  {
    fEvent = e;
  }

  TTree *operator () () const
  {
    return GetTree ();
  }

private:
    TRef fTreeRef;		// reference to the tree
  EEvent *fEvent;		//! event pointer has not to be saved.

ClassDef (EEvTreeLink, 1)};

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EEvent                                                                     //
//                                                                            //
// Root Event description in Euso. It contains an event with all possible     //
// information It is the base for all root files (input and output) At each   //
// stage of the program the event is enriched with additional data            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

class EEvent:public TObject
{
public:
  enum EActiveBranches
  {
    kShower = BIT (0),
    kAtmosphere = BIT (1),
    kDetector = BIT (2),
    kChipTrackTrigger = BIT (3),
    kLblTrackTrigger = BIT (4),
    kSimpleDetector = BIT (5),
    kPTTTrigger = BIT (6),
    kLTTTrigger = BIT (7),
    kCCB_LTTTrigger = BIT (8),
    kNone = 0,
    kAll = 0x1FF
  };

    EEvent (Int_t = kAll);
    EEvent (const EEvent &);
    virtual ~ EEvent ();

  virtual void Copy (TObject &) const;
  virtual void Clear (Option_t * = "");
  virtual void ClearAndShrink (Option_t * = "");
  virtual void Delete (Option_t * = "");

  Bool_t BranchTree (TTree *, Bool_t link = kTRUE);
  // setup EEvent structure in TTree. Returns 0 if something fails

  Bool_t SetBranches (TTree *, Bool_t clone = kFALSE);
  // set branches addresses for reading 

  Bool_t Fill (EFiller & f);
  // any filling from external data is done through this visitor

  void Build (Int_t, Int_t, const char * = 0);
  // fill event header

  // getters
  inline EHeader *GetHeader () const
  {
    return fHeader;
  }
  inline EGeometry *GetGeometry () const
  {
    return fGeometry;
  }
  inline ETruth *GetTruth () const
  {
    return fTruth;
  }
  inline EShower *GetShower () const
  {
    return fShower;
  }
  inline EAtmosphere *GetAtmosphere () const
  {
    return fAtmosphere;
  }
  inline EDetector *GetDetector () const
  {
    return fDetector;
  }
  inline ESimpleDetector *GetSimpleDetector () const
  {
    return fSimpleDetector;
  }
  inline EChipTrackTrigger *GetChipTrackTrigger () const
  {
    return fChipTrackTrigger;
  }
  inline ELblTrackTrigger *GetLblTrackTrigger () const
  {
    return fLblTrackTrigger;
  }
  inline EPTTTrigger *GetPTTTrigger () const
  {
    return fPTTTrigger;
  }
  inline ELTTTrigger *GetLTTTrigger () const
  {
    return fLTTTrigger;
  }
  inline ECCB_LTTTrigger *GetCCB_LTTTrigger () const
  {
    return fCCB_LTTTrigger;
  }

  inline ERunParameters *GetRunPars () const
  {
    return fRunPars;
  }

  inline static EEvent *GetCurrent ()
  {
    return fgCurrent;
  }
  inline static void SetCurrent (EEvent * ev)
  {
    fgCurrent = ev;
  }

  Bool_t IsLinked () const
  {
    return fTreeLink != 0;
  }
  void LinkTree (TTree *);
  void UnlinkTree ();

protected:
  TTree * GetTree ()const
  {
    return fTreeLink ? fTreeLink->GetTree () : 0;
  }

  EHeader *fHeader;		// event header
  ETruth *fTruth;		// initial conditions
  EGeometry *fGeometry;		// detector basic parameters

  EShower *fShower;		// shower simulation 
  EAtmosphere *fAtmosphere;	// atmosphere simulation
  EDetector *fDetector;		// euso detector simulation
  ESimpleDetector *fSimpleDetector;	// simple detector simulation
  EChipTrackTrigger *fChipTrackTrigger;	// chip track trigger simulation
  ELblTrackTrigger *fLblTrackTrigger;	// Lbl track trigger simulation
  EPTTTrigger *fPTTTrigger;
  ELTTTrigger *fLTTTrigger;
  ECCB_LTTTrigger *fCCB_LTTTrigger;

  ERunParameters *fRunPars;	// parameters of the detector

  EEvTreeLink *fTreeLink;	//! link to the ttree the event is attached to, if any

//    TList fBranches;
//    TList fPars;
private:

  static EEvent *fgCurrent;

ClassDef (EEvent, 1)};
#endif /* __EEVENT_HH__ */
