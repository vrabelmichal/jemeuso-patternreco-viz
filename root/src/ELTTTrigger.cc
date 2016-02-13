// $Id$
// Author: fenu2   2009/10/27

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ELTTTrigger                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// ELTTTrigger
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "root/include/ELTTTrigger.hh"
#include "root/include/ELTTTriggerSegment.hh"

ClassImp(ELTTTrigger)
TClonesArray* ELTTTrigger::fgLTTFlag = NULL;
ELTTTrigger* ELTTTrigger::fgCurrent = NULL;

//_____________________________________________________________________________
ELTTTrigger::ELTTTrigger() : TObject() {
    //
    // Constructor
    //
  if ( fgLTTFlag == 0 )
       fgLTTFlag = new TClonesArray("ELTTTriggerSegment",20000);
  
     fLTTFlag=fgLTTFlag;
        fCopy = kFALSE;
	  fNumTrigg=0;

}


//_____________________________________________________________________________
ELTTTrigger::~ELTTTrigger() {
    //
    // Destructor
    //
   Clear();
   if ( fCopy ) ClearCopy();

}

ELTTTrigger::ELTTTrigger(const ELTTTrigger& other) : TObject() {
    //
    // Copy ctor
    //
        other.Copy( *this );

}


void ELTTTrigger::Copy( TObject& other) const {
    //
    // Copy method
    //
    ELTTTrigger& trg = ( ELTTTrigger&) other;

    	trg.fNumTrigg = fNumTrigg;
       trg.fLTTFlag = (TClonesArray*)fLTTFlag->Clone();
}

//_____________________________________________________________________________
void ELTTTrigger::Clear(Option_t* opt) {

   if ( fLTTFlag ) fLTTFlag->Delete();

    fNumTrigg = 0;

}


void ELTTTrigger::ClearCopy() {
 
  delete fLTTFlag;
  fLTTFlag = 0;

}
