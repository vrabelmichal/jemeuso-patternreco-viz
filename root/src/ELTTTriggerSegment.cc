// $Id$
// Author: fenu2   2009/10/29

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ELTTTriggerSegment                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// ELTTTriggerSegment
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
#include "root/include/ELTTTriggerSegment.hh"
//#include "EEvent.hh"
//#include "Etypes.hh"
//#include <vector>
#include<TH1I.h>


ClassImp(ELTTTriggerSegment)

//_____________________________________________________________________________
ELTTTriggerSegment::ELTTTriggerSegment() {
    //
    // Constructor
    //
 }

//_____________________________________________________________________________
ELTTTriggerSegment::~ELTTTriggerSegment() {
    //
    // Destructor
    //
}

//_____________________________________________________________________________
ELTTTriggerSegment::ELTTTriggerSegment( const ELTTTriggerSegment& other ) : TObject() {
    //
    // Copy Constructor
    //
    other.Copy(*this);
}


//_____________________________________________________________________________
void ELTTTriggerSegment::Copy( TObject& other ) const {
    //
    // Copy method
    //
    TObject::Copy(other);

     ((ELTTTriggerSegment&)other).SetMaxCount(fMaxCount);
    ((ELTTTriggerSegment&)other).SetNumEvt(fNumEvt);
    ((ELTTTriggerSegment&)other).SetMaxGtu(fMaxGtu);
    ((ELTTTriggerSegment&)other).SetMaxRow(fMaxRow);
    ((ELTTTriggerSegment&)other).SetMaxCol(fMaxCol);
    ((ELTTTriggerSegment&)other).SetMaxChipID(fMaxChipID);
    ((ELTTTriggerSegment&)other).SetMaxDir(fMaxDir);
    ((ELTTTriggerSegment&)other).SetPdmID(fPdmID);
}



