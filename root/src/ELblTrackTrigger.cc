// $Id: ELblTrackTrigger.cc 2167 2005-10-10 16:21:14Z ejudd $
// Author: E.Judd   2005/07/21

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ELblTrackTrigger                                                     *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// ELblTrackTrigger
//
// This class contains all the track information from the LBL trigger algorithm
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "root/include/ELblTrackTrigger.hh"
#include "root/include/ELblTrackSegment.hh"

ClassImp(ELblTrackTrigger)

TClonesArray* ELblTrackTrigger::fgLblTracks = NULL;
ELblTrackTrigger* ELblTrackTrigger::fgCurrent = NULL;

//_____________________________________________________________________________
ELblTrackTrigger::ELblTrackTrigger() : TObject() {
    //
    // Constructor
    //
    if ( fgLblTracks == 0 )
        fgLblTracks = new TClonesArray("ELblTrackSegment",20000);
    fLblTracks = fgLblTracks;
    
    fCopy = kFALSE;
    fNumLblTracks = 0;
}

//_____________________________________________________________________________
ELblTrackTrigger::~ELblTrackTrigger() {
    //
    // Destructor
    //
    Clear();

    if ( IsCopy() ) ClearCopy();
    if ( GetCurrent() == this ) SetCurrent( 0 ); 
}

//_____________________________________________________________________________
ELblTrackTrigger::ELblTrackTrigger(const ELblTrackTrigger& other) : TObject() {
    //
    // Copy ctor
    //
    other.Copy( *this );
}

//_____________________________________________________________________________
void ELblTrackTrigger::Copy( TObject& other) const {
    //
    // Copy method
    //
    ELblTrackTrigger& trg = ( ELblTrackTrigger&) other;

    trg.fNumLblTracks = fNumLblTracks;
    trg.fLblTracks = (TClonesArray*)fLblTracks->Clone();
}

//_____________________________________________________________________________
void ELblTrackTrigger::Clear( Option_t* opt ) {
    //
    // Clear this obj
    //
    if ( fLblTracks ) fLblTracks->Delete();

    fNumLblTracks = 0;
}
   
//______________________________________________________________________________
void ELblTrackTrigger::ClearCopy() {
  // delete TClonesArray in case of copied events
  delete fLblTracks; 
  fLblTracks = 0;
}


