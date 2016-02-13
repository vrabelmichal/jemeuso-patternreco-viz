// $Id$
// Author: fenu2   2009/10/27

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EPTTTrigger                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// EPTTTrigger
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "root/include/EPTTTrigger.hh"
#include "root/include/EPTTTriggerSegment.hh"

ClassImp (EPTTTrigger)
     TClonesArray *EPTTTrigger::fgPTTFlag = NULL;
     EPTTTrigger *EPTTTrigger::fgCurrent = NULL;

//_____________________________________________________________________________
EPTTTrigger::EPTTTrigger ():TObject ()
{
  //
  // Constructor
  //
  if (fgPTTFlag == 0) {
    fgPTTFlag = new TClonesArray ("EPTTTriggerSegment", 20000);
  }
  fPTTFlag = fgPTTFlag;
  fCopy = kFALSE;
  fNumTrigg = 0;

}


//_____________________________________________________________________________
EPTTTrigger::~EPTTTrigger ()
{
  //
  // Destructor
  //
  Clear ();
  if (fCopy)
    ClearCopy ();

}

EPTTTrigger::EPTTTrigger (const EPTTTrigger & other) : TObject () {
  //
  // Copy ctor
  //
  other.Copy (*this);

}


void
EPTTTrigger::Copy (TObject & other) const {
  //
  // Copy method
  //
  EPTTTrigger & trg = (EPTTTrigger &) other;

  trg.fNumTrigg = fNumTrigg;
  trg.fPTTFlag = (TClonesArray *) fPTTFlag->Clone ();
}

//_____________________________________________________________________________
void
EPTTTrigger::Clear (Option_t * opt)
{

  if (fPTTFlag) {
    fPTTFlag->Delete();
  }

  fNumTrigg = 0;

}


void
EPTTTrigger::ClearCopy ()
{

  delete fPTTFlag;
  fPTTFlag = 0;

}
