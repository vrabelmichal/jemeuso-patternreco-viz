// $Id: EChipTrackTrigger.cc 1488 2005-02-15 13:51:18Z pesce $
// Author: R.Pesce   2005/02/15

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EChipTrackTrigger                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// EChipTrackTrigger
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "root/include/EChipTrackTrigger.hh"
#include "root/include/EChipTrackSegment.hh"

ClassImp(EChipTrackTrigger)

TClonesArray* EChipTrackTrigger::fgTracks = NULL;
EChipTrackTrigger* EChipTrackTrigger::fgCurrent = NULL;

//_____________________________________________________________________________
EChipTrackTrigger::EChipTrackTrigger() : TObject() {
    //
    // Constructor
    //
    if ( fgTracks == 0 )
        fgTracks = new TClonesArray("EChipTrackSegment",20000);
    fTracks = fgTracks;
    
    fCopy = kFALSE;
    fNumTracks = 0;
}

//_____________________________________________________________________________
EChipTrackTrigger::~EChipTrackTrigger() {
    //
    // Destructor
    //
    Clear();

    if ( IsCopy() ) ClearCopy();
    if ( GetCurrent() == this ) SetCurrent( 0 ); 
}

//_____________________________________________________________________________
EChipTrackTrigger::EChipTrackTrigger(const EChipTrackTrigger& other) : TObject() {
    //
    // Copy ctor
    //
    other.Copy( *this );
}

//_____________________________________________________________________________
void EChipTrackTrigger::Copy( TObject& other) const {
    //
    // Copy method
    //
    EChipTrackTrigger& trg = ( EChipTrackTrigger&) other;

    trg.fNumTracks = fNumTracks;
    trg.fTracks = (TClonesArray*)fTracks->Clone();
}

//_____________________________________________________________________________
void EChipTrackTrigger::Clear( Option_t* opt ) {
    //
    // Clear this obj
    //
    if ( fTracks ) fTracks->Delete();

    fNumTracks = 0;
}
   
//______________________________________________________________________________
void EChipTrackTrigger::ClearCopy() {
  // delete TClonesArray in case of copied events
  delete fTracks; 
  fTracks = 0;
}


