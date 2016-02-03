// $Id: EDetStatus.cc 2262 2005-10-24 10:42:29Z pesce $
// Author: Roberto Pesce   2005/09/27

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EDetStatus                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// EDetStatus
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "EDetStatus.hh"

ClassImp(EDetStatus)

//_____________________________________________________________________________
EDetStatus::EDetStatus() {
    //
    // Constructor
    //
}

//_____________________________________________________________________________
EDetStatus::EDetStatus( const EDetStatus& other ) : TObject() {
    //
    // Copy Constructor
    //

    other.Copy(*this);
}

//_____________________________________________________________________________
EDetStatus::~EDetStatus() {
    //
    // Destructor
    //
}

//_____________________________________________________________________________
void EDetStatus::Copy( TObject &other) const {
    //
    // Copy method
    //

    TObject::Copy(other);

    ((EDetStatus&)other).fNumActivePixels = fNumActivePixels;
    ((EDetStatus&)other).fNumSignals = fNumSignals;
    ((EDetStatus&)other).fNumBkg = fNumBkg;
    ((EDetStatus&)other).fNumHits = fNumHits;
    ((EDetStatus&)other).fNumGtu = fNumGtu;
    ((EDetStatus&)other).fNumPhotons = fNumPhotons;
    ((EDetStatus&)other).fMaxSignals = fMaxSignals;
    ((EDetStatus&)other).fMaxBkg = fMaxBkg;
    ((EDetStatus&)other).fMaxSignals = fMaxSignals;
    ((EDetStatus&)other).fPhotonHistory = fPhotonHistory;
}

//_____________________________________________________________________________
void EDetStatus::Clear( Option_t *opt ) {
    //
    // Clear method
    //

    fNumActivePixels = 0;
    fNumSignals = 0;
    fNumBkg = 0;
    fNumHits = 0;
    fNumGtu = 0;
    fNumPhotons = 0;
    fMaxSignals.Set(0);
    fMaxBkg.Set(0);
    fMaxHits.Set(0);
    fPhotonHistory.Set(0);
}

//_____________________________________________________________________________
Int_t EDetStatus::GetMaxHits( Int_t gtu ) const {
    //
    // Get the maximum number of hits registered in a pixel
    // in a given GTU
    //
    
    if ( gtu >=0 && gtu < fMaxHits.GetSize() ) return fMaxHits.At(gtu);
    else return 0;
}
//_____________________________________________________________________________
Int_t EDetStatus::GetMaxSignals( Int_t gtu ) const {
    //
    // Get the maximum number of hits registered in a pixel
    // in a given GTU
    //
    
    if ( gtu >=0 && gtu < fMaxSignals.GetSize() ) return fMaxSignals.At(gtu);
    else return 0;
}

//_____________________________________________________________________________
Int_t EDetStatus::GetMaxBkg( Int_t gtu ) const {
    //
    // Get the maximum number of hits registered in a pixel
    // in a given GTU
    //
    
    if ( gtu >=0 && gtu < fMaxBkg.GetSize() ) return fMaxBkg.At(gtu);
    else return 0;
}
