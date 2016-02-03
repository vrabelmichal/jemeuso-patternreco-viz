// $Id$
// Author: fenu2   2009/10/29

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ECCB_LTTTriggerSegment                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// ECCB_LTTTriggerSegment
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//
//#include "TObject.h"
#include "ECCB_LTTTriggerSegment.hh"
//#include "EEvent.hh"
//#include "Etypes.hh"
//#include <vector>
#include<TH1I.h>


ClassImp(ECCB_LTTTriggerSegment)

//_____________________________________________________________________________
ECCB_LTTTriggerSegment::ECCB_LTTTriggerSegment() {
    //
    // Constructor
    //
 }

//_____________________________________________________________________________
ECCB_LTTTriggerSegment::~ECCB_LTTTriggerSegment() {
    //
    // Destructor
    //
}

//_____________________________________________________________________________
ECCB_LTTTriggerSegment::ECCB_LTTTriggerSegment( const ECCB_LTTTriggerSegment& other ) : TObject() {
    //
    // Copy Constructor
    //
    other.Copy(*this);
}


//_____________________________________________________________________________
void ECCB_LTTTriggerSegment::Copy( TObject& other ) const {
    //
    // Copy method
    //
    TObject::Copy(other);

     ((ECCB_LTTTriggerSegment&)other).SetMaxCount(fMaxCount);
    ((ECCB_LTTTriggerSegment&)other).SetNumEvt(fNumEvt);
    ((ECCB_LTTTriggerSegment&)other).SetMaxGtu(fMaxGtu);
    ((ECCB_LTTTriggerSegment&)other).SetMaxRow(fMaxRow);
    ((ECCB_LTTTriggerSegment&)other).SetMaxCol(fMaxCol);
    ((ECCB_LTTTriggerSegment&)other).SetMaxChipID(fMaxChipID);
    ((ECCB_LTTTriggerSegment&)other).SetMaxDir(fMaxDir);
    ((ECCB_LTTTriggerSegment&)other).SetPdmID(fPdmID);
}



