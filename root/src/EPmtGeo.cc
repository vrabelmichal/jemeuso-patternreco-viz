// ESAF : Euso Simulation and Analysis Framework
// $Id: EPmtGeo.cc 2044 2005-07-17 01:37:58Z thea $
//  created May, 24 2004

#include "EPmtGeo.hh"

//_____________________________________________________________________________
EPmtGeo::EPmtGeo() {
    // ctor

    Clear();
}

//_____________________________________________________________________________
EPmtGeo::EPmtGeo(const EPmtGeo&) {
    // ctor

    Clear();
}

//_____________________________________________________________________________
EPmtGeo::~EPmtGeo() {
    // dtor
}

//______________________________________________________________________________
void EPmtGeo::Copy( TObject& other ) const {
    //
    //
    //

    TObject::Copy( other);
    ((EPmtGeo&)other).fStartUId = fStartUId;
    ((EPmtGeo&)other).fLastUId = fLastUId;
    ((EPmtGeo&)other).fFee     = fFee;
    ((EPmtGeo&)other).fEC      = fEC;
    ((EPmtGeo&)other).fMC      = fMC;

    ((EPmtGeo&)other).fCenterX = fCenterX;
    ((EPmtGeo&)other).fCenterY = fCenterY;
    ((EPmtGeo&)other).fCenterZ = fCenterZ;

    ((EPmtGeo&)other).fNormX   = fNormX;
    ((EPmtGeo&)other).fNormY   = fNormY;
    ((EPmtGeo&)other).fNormZ   = fNormZ;

    ((EPmtGeo&)other).fYAxisX  = fYAxisX;
    ((EPmtGeo&)other).fYAxisY  = fYAxisY;
    ((EPmtGeo&)other).fYAxisZ  = fYAxisZ;

}

//_____________________________________________________________________________
void EPmtGeo::Clear(Option_t* opt ) {

    fStartUId = 0;
    fLastUId = 0;
    fFee = 0;
    fEC = 0;
    fMC = 0;

    fCenterX = -10000;
    fCenterY = -10000;
    fCenterZ = -10000;

    fNormX = -10000; 
    fNormY = -10000; 
    fNormZ = -10000; 

    fYAxisX = -10000;
    fYAxisY = -10000;
    fYAxisZ = -10000;
}

//_____________________________________________________________________________
Float_t EPmtGeo::GetCenter( Int_t i) const {
    // return Center component by index
    
    switch(i) {
        case 0:
            return fCenterX;
        case 1:
            return fCenterY;
        case 2:
            return fCenterZ;
        default:
            Error("GetCenter(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

//_____________________________________________________________________________
Float_t EPmtGeo::GetNorm( Int_t i) const {
    // return Norm component by index
    
    switch(i) {
        case 0:
            return fNormX;
        case 1:
            return fNormY;
        case 2:
            return fNormZ;
        default:
            Error("GetNorm(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

//_____________________________________________________________________________
Float_t EPmtGeo::GetYAxis( Int_t i) const {
    // return YAxis component by index

    switch(i) {
        case 0:
            return fYAxisX;
        case 1:
            return fYAxisY;
        case 2:
            return fYAxisZ;
        default:
            Error("GetYAxis(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

//_____________________________________________________________________________
Float_t EPmtGeo::GetXAxis( Int_t i) const {
    // return XAxis component by index

    switch(i) {
        case 0:
            return fYAxisY*fNormZ-fYAxisZ*fNormY;
        case 1:
            return fYAxisZ*fNormX-fYAxisX*fNormZ;
        case 2:
            return fYAxisX*fNormY-fYAxisY*fNormX;
        default:
            Error("GetXAxis(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

