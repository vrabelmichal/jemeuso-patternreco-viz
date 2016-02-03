// $Id: EPhotoElectron.cc 2767 2006-11-15 15:50:14Z moreggia $
// Author: Sylvain Moreggia   2006/03/21

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EPhotoElectron                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// EPhotoElectron
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "EPhotoElectron.hh"
#include "Etypes.hh"

ClassImp(EPhotoElectron)

//_____________________________________________________________________________
EPhotoElectron::EPhotoElectron() : TObject() {
    //
    // Constructor
    //
    
    Clear();
}

//_____________________________________________________________________________
EPhotoElectron::~EPhotoElectron() {
    //
    // Destructor
    //
}

//_____________________________________________________________________________
EPhotoElectron::EPhotoElectron(const EPhotoElectron& other) : TObject() {
    //
    // cpy ctor
    //

    other.Copy( *this );
}

//_____________________________________________________________________________
void EPhotoElectron::Copy(TObject& other) const {
    //
    // cpy ctor
    //

    
    ((EPhotoElectron&)other).fType           = fType;
    ((EPhotoElectron&)other).fAtmoPosX       = fAtmoPosX;
    ((EPhotoElectron&)other).fAtmoPosY       = fAtmoPosY;
    ((EPhotoElectron&)other).fAtmoPosZ       = fAtmoPosZ;

    ((EPhotoElectron&)other).fPixelID        = fPixelID;           
    ((EPhotoElectron&)other).fTime           = fTime;            
    ((EPhotoElectron&)other).fSNR            = fSNR;        
    ((EPhotoElectron&)other).fTriggered      = fTriggered;         

    ((EPhotoElectron&)other).fWl             = fWl;        
    ((EPhotoElectron&)other).fShowerAge      = fShowerAge;        
    ((EPhotoElectron&)other).fAtmoHistory    = fAtmoHistory;
    ((EPhotoElectron&)other).fAtmoNbinter    = fAtmoNbinter;      
}

//_____________________________________________________________________________
void EPhotoElectron::Clear( Option_t* opt) {
    //
    // cpy ctor
    //

    
    fType        = 10;
    fAtmoPosX    = -kHuge;
    fAtmoPosY    = -kHuge;
    fAtmoPosZ    = -kHuge;

    fPixelID     = 0;           
    fTime        = kHuge;            
    fSNR         = kHuge;        
    fTriggered   = kFALSE;         

    fWl          = kHuge;        
    fShowerAge   = -kHuge;        
    fAtmoHistory = -1;
    fAtmoNbinter = -1;
}


