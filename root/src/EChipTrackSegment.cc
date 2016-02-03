// $Id: EChipTrackSegment.cc 1488 2005-02-15 13:51:18Z pesce $
// Author: R.Pesce   2005/02/15

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EChipTrackSegment                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// EChipTrackSegment
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "EChipTrackSegment.hh"

ClassImp(EChipTrackSegment)

//_____________________________________________________________________________
EChipTrackSegment::EChipTrackSegment() {
    //
    // Constructor
    //
}

//_____________________________________________________________________________
EChipTrackSegment::~EChipTrackSegment() {
    //
    // Destructor
    //
}

//_____________________________________________________________________________
EChipTrackSegment::EChipTrackSegment( const EChipTrackSegment& other ) : TObject() {
    //
    // Copy Constructor
    //
    other.Copy(*this);
}

//_____________________________________________________________________________
void EChipTrackSegment::Copy( TObject& other ) const {
    //
    // Copy method
    //
    TObject::Copy(other);

    ((EChipTrackSegment&)other).fCellId = fCellId;
    ((EChipTrackSegment&)other).fChipUid = fChipUid;
    ((EChipTrackSegment&)other).fGtuStart = fGtuStart;
    ((EChipTrackSegment&)other).fGtuEnd = fGtuEnd;
    ((EChipTrackSegment&)other).fCrossBorder = fCrossBorder;
    ((EChipTrackSegment&)other).fTrackLength = fTrackLength;
    ((EChipTrackSegment&)other).fHasHole = fHasHole;
    ((EChipTrackSegment&)other).fTriggered = fTriggered;
}

//_____________________________________________________________________________
void EChipTrackSegment::Clear( Option_t* opt ) {
    //
    // Clear method
    //
    fCellId = -1;
    fChipUid = -1;
    fGtuStart = -1;
    fGtuEnd = -1;
    fCrossBorder = kFALSE;
    fTrackLength = 0;
    fHasHole = kFALSE;
    fTriggered = kFALSE;
}
