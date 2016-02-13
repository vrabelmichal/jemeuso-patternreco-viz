// ESAF : Euso Simulation and Analysis Framework
// $Id: EPmtData.cc 2804 2008-10-09 12:10:06Z biktem $
//  created May, 24 2004

#include "root/include/EPmtData.hh"

ClassImp(EPmtData)

//_____________________________________________________________________________
EPmtData::EPmtData() {
    // ctor

    Clear();
}

//_____________________________________________________________________________
EPmtData::~EPmtData() {
    // dtor
}

//______________________________________________________________________________
void EPmtData::Copy( TObject& other ) const {
    //
    // Copy this to other
    //

    EPmtData& data = (EPmtData&)other;

    data.fPmtSide     = fPmtSide;
    data.fPmtHeight   = fPmtHeight;
    data.fPadSide     = fPadSide;
    data.fPadGap      = fPadGap;
    data.fBorderWidth = fBorderWidth;
    data.fNumPads     = fNumPads;
    data.fNumRows     = fNumRows;
    data.fNumCols     = fNumCols;

    data.fQuantum     = fQuantum;
    data.fGain        = fGain;
    data.fGainSigma   = fGainSigma;
    data.fWidth       = fWidth;
    data.fGtuLength   = fGtuLength;
}

//_____________________________________________________________________________
void EPmtData::Clear(Option_t* opt ) {

    fPmtSide     = 0;
    fPmtHeight   = 0;
    fPadSide     = 0;
    fPadGap      = 0;
    fBorderWidth = 0;
    fNumPads     = 0;
    fNumRows     = 0;
    fNumCols     = 0;

    fQuantum     = 0;
    fGain        = 0;
    fGainSigma   = 0;
    fWidth       = 0;
    fGtuLength   = 0;

}
