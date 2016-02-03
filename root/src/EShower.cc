// ESAF : Euso Simulation and Analysis Framework
// $Id: EShower.cc 2918 2011-06-10 22:22:31Z mabl $
//  created May, 23 2004

#include "EShower.hh"
#include "Etypes.hh"

ClassImp(EShower)

EShower* EShower::fgCurrent = NULL;

const Int_t fgDefClonesSize=1000;

//_____________________________________________________________________________
EShower::EShower() {
    // ctor

    if ( TClass::IsCallingNew()) {
        // this is the case of the default constructor called by Streamers and
        // other internal memory handling methods 
        fSteps = NULL;
    } else {
        // standard user defined behavior
        fSteps = new TClonesArray("EShowerStep",fgDefClonesSize);
    }

    fCopy                 = kFALSE;

    fNumSteps             = 0;
    fEnergy               = -kHuge;
    fTheta                = -kHuge;
    fPhi                  = -kHuge;
    fX1                   = -kHuge;
    fElectrEthres         = -kHuge; 
    fDirX                 = -kHuge;
    fDirY                 = -kHuge;
    fDirZ                 = -kHuge;
    fInitPosX             = -kHuge;
    fInitPosY             = -kHuge;
    fInitPosZ             = -kHuge;
    fHitGround            = kFALSE;


}

//_____________________________________________________________________________
EShower::EShower( const EShower& other ) : TObject() {
    // copy ctor

    other.Copy( *this);
}

//_____________________________________________________________________________
EShower::~EShower() {
    // dtor

    if ( fSteps ) {
        fSteps->Delete();
        delete fSteps;
        fSteps = 0;
    }

    if ( GetCurrent() == this ) SetCurrent( 0 ); 
}

//_____________________________________________________________________________
void EShower::Copy( TObject& other ) const { 
    // copy

    EShower &o = (EShower&)other;

    o.fCopy = kTRUE;
    o.fEnergy               = fEnergy;
    o.fTheta                = fTheta;
    o.fPhi                  = fPhi;
    o.fX1                   = fX1;
    o.fElectrEthres         = fElectrEthres;
    o.fDirX                 = fDirX;
    o.fDirY                 = fDirY;
    o.fDirZ                 = fDirZ;
    o.fInitPosX             = fInitPosX;
    o.fInitPosY             = fInitPosY;
    o.fInitPosZ             = fInitPosZ;
    o.fHitGround            = fHitGround;
    o.fNumSteps             = fNumSteps;

    o.fSteps = (TClonesArray*)fSteps->Clone();
}

//_____________________________________________________________________________
void EShower::Clear( Option_t* ) {
    // clear this

    if( fSteps )
        fSteps->Clear("C");

    fNumSteps = 0;

    fElectrEthres         = -kHuge; 
    fDirX                 = -kHuge;
    fDirY                 = -kHuge;
    fDirZ                 = -kHuge;
    fInitPosX             = -kHuge;
    fInitPosY             = -kHuge;
    fInitPosZ             = -kHuge;
    fHitGround            = kFALSE;
}
 

//______________________________________________________________________________
void EShower::ClearAndShrink( Option_t* opt ) {
    //
    //
    //
    Clear( opt );
    if ( fSteps ) fSteps->Expand( fgDefClonesSize );

}
