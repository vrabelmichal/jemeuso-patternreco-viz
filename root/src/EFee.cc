// $Id: EFee.cc 1896 2005-05-30 08:31:12Z thea $
// Author: M.Pallavicini May, 23 2004
    
/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EFee                                                                 *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/
  
#include "EFee.hh"

ClassImp(EFee)


//______________________________________________________________________________
//
//  Front End Electronics
//  =====================
//
//  Digital Front End electronics infos
//  For each GTU, the number of detected photons per each channel is written
//  Data is available for both DFEE and full AFEE
//

//_____________________________________________________________________________
EFee::EFee() {
    // ctor
    
    fGtu          = -1;         // gtu identifier
    fFEId         = -1;         // front end chip identifier
    fChUId        = -1;         // channel number 
    fNumSignals   = -1;         // number of signal hits
    fNumHits      = -1;         // number of detected hits
    fHasTriggered = kFALSE;     // true if it was above digital counter threshold
    fChCharge     = 0;          // channel charge
}

//_____________________________________________________________________________
EFee::EFee(const EFee& other) : TObject() {
    // copy ctor

    other.Copy( *this );
}
//_____________________________________________________________________________
EFee::~EFee() {
    // dtor
}

//_____________________________________________________________________________
void EFee::Copy( TObject& other) const {
    // copy 
    
    TObject::Copy( other);

    ((EFee&)other).fGtu          = fGtu;
    ((EFee&)other).fFEId         = fFEId;
    ((EFee&)other).fChUId        = fChUId; 
    ((EFee&)other).fNumSignals   = fNumSignals; 
    ((EFee&)other).fNumHits      = fNumHits; 
    ((EFee&)other).fHasTriggered = fHasTriggered;
    ((EFee&)other).fChCharge     = fChCharge;
}
