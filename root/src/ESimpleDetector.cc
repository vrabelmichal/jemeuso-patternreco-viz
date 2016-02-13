// $Id: ESimpleDetector.cc 2773 2006-11-17 15:54:35Z moreggia $
// Author: Sylvain Moreggia   2006/03/21

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ESimpleDetector                                                      *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// ESimpleDetector
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "root/include/ESimpDetPhoton.hh"
#include "root/include/ESimpleDetector.hh"
#include "root/include/EPhotoElectron.hh"
#include "root/include/Etypes.hh"

ClassImp(ESimpleDetector)

ESimpleDetector* ESimpleDetector::fgCurrent = NULL;
const Int_t fgDefClonesSize=10000;
    

//_____________________________________________________________________________
ESimpleDetector::ESimpleDetector() {
    //
    // Constructor
    //

    if ( TClass::IsCallingNew() ) {
        fPhotons = 0;
        fPhotoElectrons = 0;
    } else { 
        fPhotons = new TClonesArray("ESimpDetPhoton", fgDefClonesSize);
        fPhotoElectrons = new TClonesArray("EPhotoElectron", fgDefClonesSize);
    }

    fPhotonFillingMode = EDetector::kNoPhotons;  //TOFIX : if one wants photons in output

    fEventIsTriggered   = kFALSE;
    fMeanBgnd           = 0.;
    fNbPixelOnSide      = 0;
    fPixelSideLength    = 0.;
    fFirstPixelX        = 0.;   
    fFirstPixelY        = 0.; 
    fTriggerLevel       = 0.; 
    fTriggPersistency   = 0; 
    
    fNumPhotons         = 0;
    fNumPhotoElectrons  = 0;
    fFirstTime          = kHuge;
    fLastTime           = -kHuge;
    fFirstGTUTime       = kHuge;
    fNbGTUs             = 0; 
    fGTUlength          = 0.; 

}

//______________________________________________________________________________
ESimpleDetector::ESimpleDetector(const ESimpleDetector& other) : TObject() {
    //
    // copy ctor
    //
    fPhotons = 0;
    fPhotoElectrons = 0;
    other.Copy ( *this );
}


//_____________________________________________________________________________
ESimpleDetector::~ESimpleDetector() {
    //
    // Destructor
    //
    
    Clear();

    
    SafeDelete(fPhotons);
    SafeDelete(fPhotoElectrons);

    if ( GetCurrent() == this ) SetCurrent( 0 );   
}

//______________________________________________________________________________
void ESimpleDetector::Copy( TObject& other) const {
    // copy
    
    TObject::Copy(other);

    ESimpleDetector& det = (ESimpleDetector&)other;

    // copy det variables
    det.fPhotonFillingMode    = fPhotonFillingMode;
    
    det.fEventIsTriggered     = fEventIsTriggered;
    det.fMeanBgnd             = fMeanBgnd;
    det.fTriggerLevel         = fTriggerLevel;
    det.fTriggPersistency     = fTriggPersistency;
    det.fNbPixelOnSide        = fNbPixelOnSide;
    det.fPixelSideLength      = fPixelSideLength;
    det.fFirstPixelX          = fFirstPixelX;
    det.fFirstPixelY          = fFirstPixelY;
    
    det.fNumPhotoElectrons    = fNumPhotoElectrons;
    det.fNumPhotons           = fNumPhotons;
    det.fFirstTime            = fFirstTime;
    det.fLastTime             = fLastTime;
    det.fFirstGTUTime         = fFirstGTUTime;
    det.fNbGTUs               = fNbGTUs;
    det.fGTUlength            = fGTUlength;

    SafeDelete(det.fPhotons);
    SafeDelete(det.fPhotoElectrons);

    // create TClonesArray
    det.fPhotons          = (TClonesArray*)fPhotons->Clone();
    det.fPhotoElectrons   = (TClonesArray*)fPhotoElectrons->Clone();
}

//______________________________________________________________________________
void ESimpleDetector::Clear( Option_t* opt ) {
    // build header
    
    if ( fPhotons ) fPhotons->Clear(opt);
    if ( fPhotoElectrons ) fPhotoElectrons->Clear(opt);


    fPhotonFillingMode = EDetector::kNoPhotons;   //TOFIX : if one wants photons in output

    fEventIsTriggered   = kFALSE;
    fMeanBgnd           = 0.;
    fTriggerLevel       = 0.;
    fTriggPersistency   = 0;
    fNbPixelOnSide      = 0;
    fPixelSideLength    = 0.;
    fFirstPixelX        = 0.;   
    fFirstPixelY        = 0.; 
    
    fNumPhotons         = 0;
    fFirstTime          = kHuge;
    fLastTime           = -kHuge;
    fNumPhotoElectrons  = 0;
    fFirstGTUTime       = kHuge;
    fNbGTUs             = 0; 

}

//______________________________________________________________________________
void ESimpleDetector::ClearAndShrink( Option_t* opt) {
    //
    //
    //

    Clear( opt );
    if( fPhotons )        fPhotons->Expand( fgDefClonesSize );
    if( fPhotoElectrons ) fPhotoElectrons->Expand( fgDefClonesSize );
}

