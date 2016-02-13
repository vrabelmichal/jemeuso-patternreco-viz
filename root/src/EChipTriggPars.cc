// $Id: EChipTriggPars.cc 2264 2005-10-24 14:30:39Z pesce $
// Author:    2005/09/28

/*****************************************************************************
 *                                                                           *
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EChipTriggPars                                                       *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// EChipTriggPars
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "root/include/EChipTriggPars.hh"
#include "root/include/ERunParameters.hh"
#include "root/include/ESystemOfUnits.hh"

using namespace TMath;
using namespace sou;

ClassImp(EChipTriggPars)

//_____________________________________________________________________________
EChipTriggPars::EChipTriggPars() {
    //
    // Constructor
    //
    Clear();
}

//_____________________________________________________________________________
EChipTriggPars::EChipTriggPars( const EChipTriggPars& other ) {
    //
    // Copy constructor
    //
    
    other.Copy(*this);
}

//_____________________________________________________________________________
EChipTriggPars::~EChipTriggPars() {
    //
    // Destructor
    //
}

//_____________________________________________________________________________
void EChipTriggPars::Copy( TObject& other ) const {
    //
    // Copy method
    //

    ETriggPars::Copy(other);

    EChipTriggPars& o = (EChipTriggPars&) other;

    o.fId = fId;
    o.fName = fName;
    o.fThreshold = fThreshold;
    o.fHasRelativeThreshold = fHasRelativeThreshold;
    o.fMinTrackLength = fMinTrackLength;
    o.fMaxTrackLength = fMaxTrackLength;
    o.fMinTriggerTrackLength = fMinTriggerTrackLength;
    o.fMinTriggerTwoLength = fMinTriggerTwoLength;
    o.fMaxTwoLength = fMaxTwoLength;
    o.fOnlyWithSignal = fOnlyWithSignal;
    o.fAcceptHole = fAcceptHole;
    o.fRunParsRef = fRunParsRef;
}
//_____________________________________________________________________________
void EChipTriggPars::Clear( Option_t *opt ) {
    //
    // Clear method
    //

    fId = (ETriggerTypeIdentifier)0;
    fName = 0;
    fThreshold = -1;
    fHasRelativeThreshold = kFALSE;
    fMinTrackLength = -1;
    fMaxTrackLength = -1;
    fMinTriggerTrackLength = -1;
    fMinTriggerTwoLength = -1;
    fMaxTwoLength = -1;
    fOnlyWithSignal = kFALSE;
    fAcceptHole = kFALSE;
    TRef dummy; fRunParsRef = dummy;
}

//_____________________________________________________________________________
Int_t EChipTriggPars::GetThreshold( Int_t cellid ) {
    //
    // Get the trigger threshold in a given microcell
    //

    if (!HasRelativeThreshold() ) return fThreshold;
    
    Double_t rate = ((ERunParameters*)fRunParsRef.GetObject())->GetNightGlowRate(cellid);
    rate *= ((ERunParameters*)fRunParsRef.GetObject())->GetPmtData().GetGtuLength()/microsecond;

    return (Int_t)Ceil(rate + fThreshold + Sqrt(rate));
    
}
