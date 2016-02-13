// $Id$
// Author: fenu2   2009/10/27

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ECCB_LTTTrigger                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// ECCB_LTTTrigger
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "root/include/ECCB_LTTTrigger.hh"
#include "root/include/ECCB_LTTTriggerSegment.hh"

ClassImp(ECCB_LTTTrigger)
TClonesArray* ECCB_LTTTrigger::fgCCB_LTTFlag = NULL;
ECCB_LTTTrigger* ECCB_LTTTrigger::fgCurrent = NULL;

//_____________________________________________________________________________
ECCB_LTTTrigger::ECCB_LTTTrigger() : TObject() {
    //
    // Constructor
    //
  if ( fgCCB_LTTFlag == 0 )
       fgCCB_LTTFlag = new TClonesArray("ECCB_LTTTriggerSegment",20000);
  
     fCCB_LTTFlag=fgCCB_LTTFlag;
        fCopy = kFALSE;
	  fNumTrigg=0;

}


//_____________________________________________________________________________
ECCB_LTTTrigger::~ECCB_LTTTrigger() {
    //
    // Destructor
    //
   Clear();
   if ( fCopy ) ClearCopy();

}

ECCB_LTTTrigger::ECCB_LTTTrigger(const ECCB_LTTTrigger& other) : TObject() {
    //
    // Copy ctor
    //
        other.Copy( *this );

}


void ECCB_LTTTrigger::Copy( TObject& other) const {
    //
    // Copy method
    //
    ECCB_LTTTrigger& trg = ( ECCB_LTTTrigger&) other;

    	trg.fNumTrigg = fNumTrigg;
       trg.fCCB_LTTFlag = (TClonesArray*)fCCB_LTTFlag->Clone();
}

//_____________________________________________________________________________
void ECCB_LTTTrigger::Clear(Option_t* opt) {

   if ( fCCB_LTTFlag ) fCCB_LTTFlag->Delete();

    fNumTrigg = 0;

}


void ECCB_LTTTrigger::ClearCopy() {
 
  delete fCCB_LTTFlag;
  fCCB_LTTFlag = 0;

}
