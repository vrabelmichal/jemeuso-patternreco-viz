// ESAF : Euso Simulation and Analysis Framework
// $Id: ETruth.cc 3069 2014-04-15 13:46:25Z fenu $
// A.Thea created May, 23 2004


/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ETruth                                                               *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/

#include "ETruth.hh"
#include "Etypes.hh"

//______________________________________________________________________________
//
//   ETruth
//   ======
// 
//   MonteCarlo Truth object. Informations about the real event
//   In case of EECR, contains infos about the original particle, 
//   direction, energy, type
//   In case of other backgrounds, informations about the real process
//

ClassImp(ETruth)

//_____________________________________________________________________________
ETruth::ETruth() {
    // ctor
    Clear();

}

//_____________________________________________________________________________
ETruth::ETruth( const ETruth& other ) : TObject() {
    // copy ctor

    other.Copy( *this );
}

//_____________________________________________________________________________
ETruth::~ETruth() {
    // dtor
}

//______________________________________________________________________________
void ETruth::Streamer(TBuffer &R__b)
{
   // Stream an object of class ETruth.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c);
      if (R__v == 1) { 
          TObject::Streamer(R__b);
          EFillable::Streamer(R__b);
          R__b >> fTrueEnergy;
          R__b >> fTrueTheta;
          R__b >> fTruePhi;
          fTrueParticleName.Streamer(R__b);
          R__b >> fTrueParticleCode;
          R__b >> fTrueInitPosX;
          R__b >> fTrueInitPosY;
          R__b >> fTrueInitPosZ;
          R__b >> fTrueX1;
          R__b >> fTrueEarthImpactX;
          R__b >> fTrueEarthImpactY;
          R__b >> fTrueEarthImpactZ;
          R__b >> fTrueEarthAge;
          R__b >> fTrueShowerMaxPosX;
          R__b >> fTrueShowerMaxPosY;
          R__b >> fTrueShowerMaxPosZ;
          R__b >> fTrueShowerXMax;
          R__b >> fTrueHclouds;
          R__b >> fTrueCloudsthick;
          R__b >> fTrueCloudsOD;
          R__b >> fTrueLatitude;
          R__b >> fTrueLongitude;
          R__b >> fTrueDate;
          fTrueTOAImpactX     = -kHuge;
          fTrueTOAImpactY     = -kHuge;
          fTrueTOAImpactZ     = -kHuge;
          R__b.CheckByteCount(R__s, R__c, ETruth::IsA());
      } else if  (R__v == 2) { 
          TObject::Streamer(R__b);
          EFillable::Streamer(R__b);
          R__b >> fTrueEnergy;
          R__b >> fTrueTheta;
          R__b >> fTruePhi;
          fTrueParticleName.Streamer(R__b);
          R__b >> fTrueParticleCode;
          R__b >> fTrueInitPosX;
          R__b >> fTrueInitPosY;
          R__b >> fTrueInitPosZ;
          R__b >> fTrueX1;
          R__b >> fTrueEarthImpactX;
          R__b >> fTrueEarthImpactY;
          R__b >> fTrueEarthImpactZ;
          R__b >> fTrueTOAImpactX;
          R__b >> fTrueTOAImpactY;
          R__b >> fTrueTOAImpactZ;
          R__b >> fTrueEarthAge;
          R__b >> fTrueShowerMaxPosX;
          R__b >> fTrueShowerMaxPosY;
          R__b >> fTrueShowerMaxPosZ;
          R__b >> fTrueShowerXMax;
          R__b >> fTrueHclouds;
          R__b >> fTrueCloudsthick;
          R__b >> fTrueCloudsOD;
          R__b >> fTrueLatitude;
          R__b >> fTrueLongitude;
          R__b >> fTrueDate;
          fTrueHGround        = -kHuge;
          fTrueGroundAlbedo   = -kHuge;
          fTrueGroundSpecular = -kHuge;
          R__b.CheckByteCount(R__s, R__c, ETruth::IsA());
      } else {
          ETruth::Class()->ReadBuffer(R__b,this, R__v, R__s, R__c);
      }
   } else {
       ETruth::Class()->WriteBuffer(R__b,this);
   }
}

//_____________________________________________________________________________
void ETruth::Clear( Option_t* ) {

    fTrueEnergy         = 0;
    fTrueTheta          = 0;
    fTruePhi            = 0;
    fTrueParticleName.Resize(0);
    fTrueParticleCode   = 0;
    fTrueInitPosX       = -kHuge;
    fTrueInitPosY       = -kHuge;
    fTrueInitPosZ       = -kHuge;
    fTrueX1             = 0;
    fTrueEarthImpactX   = -kHuge;
    fTrueEarthImpactY   = -kHuge;
    fTrueEarthImpactZ   = -kHuge;
    fTrueEarthAge       = 0;
    fTrueShowerMaxPosX  = -kHuge;
    fTrueShowerMaxPosY  = -kHuge;
    fTrueShowerMaxPosZ  = -kHuge;
    fTrueShowerXMax     = 0;
    fTrueTOAImpactX     = -kHuge;
    fTrueTOAImpactY     = -kHuge;
    fTrueTOAImpactZ     = -kHuge;
    fTrueHclouds        = -kHuge;

    fTrueCloudsthick    = 0;
    fTrueCloudsOD       = 0;
    fTrueLatitude       = 0;
    fTrueLongitude      = 0;
    fTrueDate           = 0;
    fTrueHGround        = -kHuge;
    fTrueGroundAlbedo   = -kHuge;
    fTrueGroundSpecular = -kHuge;
}

//_____________________________________________________________________________
void ETruth::Copy( TObject& other) const {
    // copy 
    
    ETruth& truth = (ETruth&)other; 

    truth.fTrueEnergy         = fTrueEnergy;
    truth.fTrueTheta          = fTrueTheta;
    truth.fTruePhi            = fTruePhi;
    truth.fTrueParticleName   = fTrueParticleName;
    truth.fTrueParticleCode   = fTrueParticleCode;
    truth.fTrueInitPosX       = fTrueInitPosX;
    truth.fTrueInitPosY       = fTrueInitPosY;
    truth.fTrueInitPosZ       = fTrueInitPosZ;
    truth.fTrueX1             = fTrueX1;
    truth.fTrueEarthImpactX   = fTrueEarthImpactX;
    truth.fTrueEarthImpactY   = fTrueEarthImpactY;
    truth.fTrueEarthImpactZ   = fTrueEarthImpactZ;
    truth.fTrueEarthAge       = fTrueEarthAge;
    truth.fTrueShowerMaxPosX  = fTrueShowerMaxPosX;
    truth.fTrueShowerMaxPosY  = fTrueShowerMaxPosY;
    truth.fTrueShowerMaxPosZ  = fTrueShowerMaxPosZ;
    truth.fTrueShowerXMax     = fTrueShowerXMax;
    truth.fTrueTOAImpactX     = fTrueTOAImpactX;
    truth.fTrueTOAImpactY     = fTrueTOAImpactY;
    truth.fTrueTOAImpactZ     = fTrueTOAImpactZ;
    truth.fTrueHclouds        = fTrueHclouds;

    truth.fTrueCloudsthick    = fTrueCloudsthick;
    truth.fTrueCloudsOD       = fTrueCloudsOD;
    truth.fTrueLatitude       = fTrueLatitude;
    truth.fTrueLongitude      = fTrueLongitude;
    truth.fTrueDate           = fTrueDate;
    truth.fTrueHGround        = fTrueHGround;
    truth.fTrueGroundAlbedo   = fTrueGroundAlbedo;
    truth.fTrueGroundSpecular = fTrueGroundSpecular;
}

//_____________________________________________________________________________
Float_t ETruth::GetTrueThetaLocal() const {
    //
    // returns theta in frame defined at TOAimpact    
    //
    
    const static Float_t EarthRadius = 6.370949e9;  // esaf unit in mm
    
    // init
    TVector3 toaimpact(fTrueTOAImpactX,fTrueTOAImpactY,fTrueTOAImpactZ);
    TVector3 omega_local(1,0,0);
    omega_local.SetMagThetaPhi(1.,fTrueTheta,fTruePhi);
    
    // Change fOmega from MES frame to local frame, using TOA impact as the reference vector
    TVector3 v1(toaimpact);
    v1 += TVector3(0,0,EarthRadius);
    v1 = v1.Unit();
    TVector3 vrot;
    TVector3 Uz(0,0,1);
    vrot = Uz.Cross(v1);
    if(vrot.Mag() > 1e-6) omega_local.Rotate(-v1.Theta(),vrot);
    
    return omega_local.Theta();
}

//_____________________________________________________________________________
Float_t ETruth::GetTruePhiLocal() const {
    //
    // returns phi in frame defined at TOAimpact    
    //

    const static Float_t EarthRadius = 6.370949e9;  // esaf unit in mm
    
    // init
    TVector3 toaimpact(fTrueTOAImpactX,fTrueTOAImpactY,fTrueTOAImpactZ);
    TVector3 omega_local(1,0,0);
    omega_local.SetMagThetaPhi(1.,fTrueTheta,fTruePhi);
    
    // Change fOmega from MES frame to local frame, using TOA impact as the reference vector
    TVector3 v1(toaimpact);
    v1 += TVector3(0,0,EarthRadius);
    v1 = v1.Unit();
    TVector3 vrot;
    TVector3 Uz(0,0,1);
    vrot = Uz.Cross(v1);
    if(vrot.Mag() > 1e-6) omega_local.Rotate(-v1.Theta(),vrot);
    
    return omega_local.Phi();
}

