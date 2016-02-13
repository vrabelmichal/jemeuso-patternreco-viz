// ESAF : Euso Simulation and Analysis Framework
// $Id: EDetPhoton.cc 3007 2012-01-11 10:06:56Z fenu $
//  created May, 18 2004

#include "root/include/EDetPhoton.hh"
#include "root/include/Etypes.hh"

ClassImp(EDetPhoton)

//_____________________________________________________________________________
EDetPhoton::EDetPhoton(){
    // ctor

    Clear();
}

//_____________________________________________________________________________
EDetPhoton::~EDetPhoton() {
    // dtor
}

//_____________________________________________________________________________
EDetPhoton::EDetPhoton(const EDetPhoton& other) {
    // copy ctor
    
    other.Copy( *this );
}

//_____________________________________________________________________________
EDetPhoton::EDetPhoton(const EPhoton& other) {
    // copy ctor
    
    Clear();
    other.Copy( *this );
}

//_____________________________________________________________________________
void EDetPhoton::Copy( TObject& other) const {
    // copy 
    
//    ((EDetPhoton&)other).fType           = fType;
    ((EDetPhoton&)other).fStatusBits     = fStatusBits;
    ((EDetPhoton&)other).fShowerPosX     = fShowerPosX;
    ((EDetPhoton&)other).fShowerPosY     = fShowerPosY;
    ((EDetPhoton&)other).fShowerPosZ     = fShowerPosZ;
    ((EDetPhoton&)other).fAge             = fAge;

//    ((EDetPhoton&)other).fTheta          = fTheta;           
//    ((EDetPhoton&)other).fPhi            = fPhi;            
//    ((EDetPhoton&)other).fLambda         = fLambda;        
//    ((EDetPhoton&)other).fTime           = fTime;         

    ((EDetPhoton&)other).fHistory        = fHistory;
    ((EDetPhoton&)other).fFate           = fFate;        
//    ((EDetPhoton&)other).fPosX           = fPosX;      
//    ((EDetPhoton&)other).fPosY           = fPosY;      
//    ((EDetPhoton&)other).fPosZ           = fPosZ;
    ((EDetPhoton&)other).fIdealFocalPosX = fIdealFocalPosX;
    ((EDetPhoton&)other).fIdealFocalPosY = fIdealFocalPosY;
    ((EDetPhoton&)other).fIdealFocalPosZ = fIdealFocalPosZ;

    ((EDetPhoton&)other).fMacroCell      = fMacroCell;        
    ((EDetPhoton&)other).fFe             = fFe;            
    ((EDetPhoton&)other).fGtu            = fGtu;         

    ((EDetPhoton&)other).fPixelUID       = fPixelUID;        
    ((EDetPhoton&)other).fSignalId       = fSignalId;  
    ((EDetPhoton&)other).fCharge         = fCharge;         
    ((EDetPhoton&)other).fIPeak          = fIPeak;         
    ((EDetPhoton&)other).fSignalTime     = fSignalTime;   
}

//_____________________________________________________________________________
void EDetPhoton::Clear( Option_t* opt) {

    EPhoton::Clear(opt);

    fStatusBits     = 0;
    fShowerPosX     = -kHuge;
    fShowerPosY     = -kHuge; 
    fShowerPosZ     = -kHuge;
    fAge     = 0;

    fHistory        = 0; 
    fFate           = 0;
    fIdealFocalPosX = -kHuge;
    fIdealFocalPosY = -kHuge;
    fIdealFocalPosZ = -kHuge;

    fMacroCell      = 0;
    fFe             = 0;
    fGtu            = -1;

    fPixelUID       = 0;
    fSignalId       = 0;
    fCharge         = 0;
    fIPeak          = 0;
    fSignalTime     = 0;

}


