// ESAF : Euso Simulation and Analysis Framework
// $Id: EAnglePixelMap.cc 2498 2006-02-22 12:57:29Z thea $
// Author: A.Thea

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EAnglePixelMap                                                       *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/

#include "root/include/EAnglePixelMap.hh"

ClassImp(EAnglePixelMap)

//_____________________________________________________________________________
EAnglePixelMap::EAnglePixelMap() {
    //
    // Constructor
    // 

    fThetaFOV       = 0;
    fSigmaThetaFOV  = 0;
    fPhiFOV         = 0;
    fSigmaPhiFOV    = 0;
    Clear();
}

//_____________________________________________________________________________
EAnglePixelMap::EAnglePixelMap( Int_t n ) {
    //
    // Constructor
    //

    Clear();
}

//_____________________________________________________________________________
EAnglePixelMap::EAnglePixelMap( const EAnglePixelMap& other ) : TObject() {
    // 
    // Copy constructor

    other.Copy( *this );
}

//_____________________________________________________________________________
EAnglePixelMap::~EAnglePixelMap() {
    // dtor
}

//_____________________________________________________________________________
void EAnglePixelMap::Clear( Option_t* opt) {
    // initialize

    fNumPixels      = 0;

    if ( fThetaFOV )      delete [] fThetaFOV;
    if ( fSigmaThetaFOV ) delete [] fSigmaThetaFOV;
    if ( fPhiFOV )        delete [] fPhiFOV;
    if ( fSigmaPhiFOV )   delete [] fSigmaPhiFOV;
    
    fThetaFOV       = 0;
    fSigmaThetaFOV  = 0;
    fPhiFOV         = 0;
    fSigmaPhiFOV    = 0;

}

//_____________________________________________________________________________
void EAnglePixelMap::Copy( TObject& other ) const {
    // copy

    TObject::Copy(other);

    ((EAnglePixelMap&)other).Resize( GetNumPixels() );

    for ( Int_t i(0); i < GetNumPixels(); i++ ) {
        ((EAnglePixelMap&)other).fThetaFOV[i]      = fThetaFOV[i];
        ((EAnglePixelMap&)other).fSigmaThetaFOV[i] = fSigmaThetaFOV[i];
        ((EAnglePixelMap&)other).fPhiFOV[i]        = fPhiFOV[i];
        ((EAnglePixelMap&)other).fSigmaPhiFOV[i]   = fSigmaPhiFOV[i];
    }
}

//_____________________________________________________________________________
Int_t EAnglePixelMap::Resize( Int_t n ) {
    // resize the map to n

    Clear();
    fNumPixels = n;

    fThetaFOV      = new Float_t[n];
    fSigmaThetaFOV = new Float_t[n];
    fPhiFOV        = new Float_t[n];
    fSigmaPhiFOV   = new Float_t[n];

    return n;   
}

