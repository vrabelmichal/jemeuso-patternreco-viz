// $Id: ELblTrackSegment.cc 2167 2005-10-10 16:21:14Z ejudd $
// Author: E.Judd   2005/07/21

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ELblTrackSegment                                                     *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// ELblTrackSegment
//
// Contains all the information about an individual track found by the LBL trigger
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "root/include/ELblTrackSegment.hh"

ClassImp(ELblTrackSegment)

//_____________________________________________________________________________
ELblTrackSegment::ELblTrackSegment() {
    //
    // Constructor
    //

    Clear();

}

//_____________________________________________________________________________
ELblTrackSegment::~ELblTrackSegment() {
    //
    // Destructor
    //
}

//_____________________________________________________________________________
ELblTrackSegment::ELblTrackSegment( const ELblTrackSegment& other ) : TObject() {
    //
    // Copy Constructor
    //
    other.Copy(*this);
}

//_____________________________________________________________________________
void ELblTrackSegment::Copy( TObject& other ) const {
    //
    // Copy method
    //
    TObject::Copy(other);

    ((ELblTrackSegment&)other).fCellId = fCellId;
    ((ELblTrackSegment&)other).fChipUid = fChipUid;
    ((ELblTrackSegment&)other).fGtuStart = fGtuStart;
    ((ELblTrackSegment&)other).fGtuEnd = fGtuEnd;
    ((ELblTrackSegment&)other).fRowStart = fRowStart;
    ((ELblTrackSegment&)other).fRowEnd = fRowEnd;
    ((ELblTrackSegment&)other).fColStart = fColStart;
    ((ELblTrackSegment&)other).fColEnd = fColEnd;
    ((ELblTrackSegment&)other).fNumSegs = fNumSegs;
    ((ELblTrackSegment&)other).fSum = fSum;
    ((ELblTrackSegment&)other).fTriggerID = fTriggerID;
}

//_____________________________________________________________________________
void ELblTrackSegment::Clear( Option_t* opt ) {
    //
    // Clear method
    //
    fCellId = -1;
    fChipUid = -1;
    fGtuStart = -1;
    fGtuEnd = -1;
    fRowStart = -1;
    fRowEnd = -1;
    fColStart = -1;
    fColEnd = -1;
    fNumSegs = 0;
    fSum = 0;
    fTriggerID = -1;
}
