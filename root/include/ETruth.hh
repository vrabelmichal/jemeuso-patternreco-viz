// $Id: ETruth.hh 2917 2011-06-10 11:01:18Z mabl $
// A.Thea created May, 23 2004

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ETruth                                                               *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/

#ifndef __ETRUTH_HH__
#define __ETRUTH_HH__

#include "TObject.h"
#include "TString.h"
#include "TVector3.h"

#include "EFillable.hh"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// ETruth                                                                     //
//                                                                            //
// MonteCarlo truth object                                                    //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

class ETruth : public TObject, public EFillable {
public:
    ETruth();
    ETruth( const ETruth& );
    
    virtual ~ETruth();

    virtual void Clear( Option_t* = "" );
    virtual void Copy( TObject& ) const;

    // getters
    inline Float_t GetTrueEnergy() const { return fTrueEnergy; }
    inline Float_t GetTrueTheta() const { return fTrueTheta; }
    Float_t GetTrueThetaLocal() const; // in frame defined at TOAimpact
    inline Float_t GetTruePhi() const { return fTruePhi; }
    Float_t GetTruePhiLocal() const;   // in frame defined at TOAimpact
    inline const char* GetTrueParticleName() { return fTrueParticleName.Data();}  
    inline Int_t   GetTrueParticleCode() const { return fTrueParticleCode;}  
    inline Float_t GetTrueInitPos( Int_t ) const;
    inline Float_t GetTrueX1() const { return fTrueX1; }               
    inline Float_t GetTrueEarthImpact( Int_t ) const;
    inline Float_t GetTrueEarthAge() const { return fTrueEarthAge;}          
    inline Float_t GetTrueShowerMaxPos( Int_t ) const;
    inline Float_t GetTrueShowerXMax() const { return fTrueShowerXMax;}
    inline Float_t GetTrueTOAImpact( Int_t ) const;
    inline Float_t GetTrueHclouds() const { return fTrueHclouds; }
    inline Float_t GetTrueCloudsthick() const { return fTrueCloudsthick; }
    inline Float_t GetTrueCloudsOD() const { return fTrueCloudsOD; }
    inline Float_t GetTrueLatitude() const { return fTrueLatitude; }
    inline Float_t GetTrueLongitude() const { return fTrueLongitude; }
    inline Float_t GetTrueDate() const { return fTrueDate; }
    inline Float_t GetTrueHGround() const { return fTrueHGround; }
    inline Float_t GetTrueGroundAlbedo() const { return fTrueGroundAlbedo; }
    inline Float_t GetTrueGroundSpecular() const { return fTrueGroundSpecular; }

    inline TVector3 GetTrueInitPos() const;
    inline TVector3 GetTrueEarthImpact() const;
    inline TVector3 GetTrueShowerMaxPos() const;
    inline TVector3 GetTrueTOAImpact() const;


    inline void SetTrueEnergy( Float_t e ) { fTrueEnergy = e; }
    inline void SetTrueTheta( Float_t theta ) { fTrueTheta = theta; }
    inline void SetTruePhi( Float_t phi ) { fTruePhi = phi; }
    inline void SetTrueParticleCode( Int_t code ) { fTrueParticleCode = code; }  
    inline void SetTrueInitPos( Int_t i, Float_t x );
    inline void SetTrueX1( Float_t x1 ) { fTrueX1 = x1; }               
    inline void SetTrueEarthImpact( Int_t i, Float_t x );
    inline void SetTrueEarthAge( Float_t ea ) { fTrueEarthAge = ea; }          
    inline void SetTrueShowerMaxPos( Int_t i, Float_t x ) ;
    inline void SetTrueShowerXMax( Float_t xmax ) { fTrueShowerXMax = xmax; }
    inline void SetTrueTOAImpact( Int_t i, Float_t x );
    inline void SetTrueHclouds( Float_t h ) { fTrueHclouds = h; }
    inline void SetTrueCloudsthick( Float_t t ) { fTrueCloudsthick = t; }
    inline void SetTrueCloudsOD( Float_t od ) { fTrueCloudsOD = od; }
    inline void SetTrueLatitude( Float_t lat ) { fTrueLatitude = lat; }
    inline void SetTrueLongitude( Float_t longi ) { fTrueLongitude = longi; }
    inline void SetTrueDate( Float_t dat ) { fTrueDate = dat; }
    inline void SetTrueHGround( Float_t h ) { fTrueHGround = h; }
    inline void SetTrueGroundAlbedo( Float_t alb ) { fTrueGroundAlbedo = alb; }
    inline void SetTrueGroundSpecular( Float_t spec ) { fTrueGroundSpecular = spec; }

    inline void SetTrueInitPos( const TVector3& v );
    inline void SetTrueEarthImpact( const TVector3& v );
    inline void SetTrueShowerMaxPos( const TVector3& v ) ;
    inline void SetTrueTOAImpact( const TVector3& v );



private:
    Float_t fTrueEnergy;            // primary EECR energy (eV)
    Float_t fTrueTheta;             // incidence angle (rad)
    Float_t fTruePhi;               // azimuth; Phi=0 corresponds Y=0
    TString fTrueParticleName;      // particle name (see above)
    Int_t   fTrueParticleCode;      // same as name with code instead of strings
    Float_t fTrueInitPosX;          // first interaction point (3D coord, Km)
    Float_t fTrueInitPosY;          // first interaction point (3D coord, Km)
    Float_t fTrueInitPosZ;          // first interaction point (3D coord, Km)
    Float_t fTrueX1;                // interaction depth in g/cm^2
    Float_t fTrueEarthImpactX;      // impact of shower on earth (clouds ignored)
    Float_t fTrueEarthImpactY;      // impact of shower on earth (clouds ignored)
    Float_t fTrueEarthImpactZ;      // impact of shower on earth (clouds ignored)
    Float_t fTrueTOAImpactX;        // impact of shower on top of the atmosphere
    Float_t fTrueTOAImpactY;        // impact of shower on top of the atmosphere
    Float_t fTrueTOAImpactZ;        // impact of shower on top of the atmosphere
    Float_t fTrueEarthAge;          // age of the shower at impact
    Float_t fTrueShowerMaxPosX;     // shower max position (3D coord, Km)
    Float_t fTrueShowerMaxPosY;     // shower max position (3D coord, Km)
    Float_t fTrueShowerMaxPosZ;     // shower max position (3D coord, Km)
    Float_t fTrueShowerXMax;        // shower max depth (g/cm^2)
    Float_t fTrueHclouds;           // altitude of the clouds. smaller than 0 means no clouds 
    Float_t fTrueCloudsthick;       // clouds thickness
    Float_t fTrueCloudsOD;          // clouds OD 
    Float_t fTrueLatitude;          // geodetic latitude (also used to identify std atmospheres)
                                    // USStd         : 100
				    // Tropical      : 101
				    // MidLat Summer : 102
				    // MidLat Winter : 103
				    // LinsleyAtmo   : 104
    Float_t fTrueLongitude;         // geodetic longitude
    Float_t fTrueDate;              // event date
    Float_t fTrueHGround;           // ground altitude
    Float_t fTrueGroundAlbedo;      // ground albedo
    Float_t fTrueGroundSpecular;    // ground specular component intensity

    SetEVisitable()

    ClassDef(ETruth,3)

};

inline TVector3 ETruth::GetTrueInitPos() const {
    return TVector3(fTrueInitPosX, fTrueInitPosY, fTrueInitPosZ);
}

inline void ETruth::SetTrueInitPos( const TVector3& v ){
    fTrueInitPosX = v.X();
    fTrueInitPosY = v.Y();
    fTrueInitPosZ = v.Z();
}

inline Float_t ETruth::GetTrueInitPos( Int_t i ) const {
    // return TrueInitPos component by index

    switch(i) {
        case 0:
            return fTrueInitPosX;
        case 1:
            return fTrueInitPosY;
        case 2:
            return fTrueInitPosZ;
        default:
            Error("GetTrueInitPos(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

inline void ETruth::SetTrueInitPos( Int_t i, Float_t x ) {
    // TrueInitPos component by index

    switch(i) {
        case 0:
            fTrueInitPosX = x;
	    break;
        case 1:
            fTrueInitPosY = x;
	    break;
        case 2:
            fTrueInitPosZ = x;
	    break;
        default:
            Error("SetTrueInitPos(i)", "bad index (%d)",i);
    }
}

inline TVector3 ETruth::GetTrueEarthImpact() const {
    return TVector3(fTrueEarthImpactX, fTrueEarthImpactY, fTrueEarthImpactZ);
}

inline void ETruth::SetTrueEarthImpact( const TVector3& v ){
    fTrueEarthImpactX = v.X();
    fTrueEarthImpactY = v.Y();
    fTrueEarthImpactZ = v.Z();
}

inline Float_t ETruth::GetTrueEarthImpact( Int_t i) const {
    // return TrueEarthImpact component by index

    switch(i) {
        case 0:
            return fTrueEarthImpactX;
        case 1:
            return fTrueEarthImpactY;
        case 2:
            return fTrueEarthImpactZ;
        default:
            Error("GetTrueEarthImpact(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

inline void ETruth::SetTrueEarthImpact( Int_t i, Float_t x ) {
    // TrueEarthImpact component by index

    switch(i) {
        case 0:
            fTrueEarthImpactX = x;
	    break;
        case 1:
            fTrueEarthImpactY = x;
	    break;
        case 2:
            fTrueEarthImpactZ = x;
	    break;
        default:
            Error("SetTrueEarthImpact(i)", "bad index (%d)",i);
    }
}

inline TVector3 ETruth::GetTrueTOAImpact() const {
    return TVector3(fTrueTOAImpactX, fTrueTOAImpactY, fTrueTOAImpactZ);
}

inline void ETruth::SetTrueTOAImpact( const TVector3& v ){
    fTrueTOAImpactX = v.X();
    fTrueTOAImpactY = v.Y();
    fTrueTOAImpactZ = v.Z();
}

inline Float_t ETruth::GetTrueTOAImpact( Int_t i) const {
    // return TrueTOAImpact component by index

    switch(i) {
        case 0:
            return fTrueTOAImpactX;
        case 1:
            return fTrueTOAImpactY;
        case 2:
            return fTrueTOAImpactZ;
        default:
            Error("GetTrueTOAImpact(i)", "bad index (%d) returning 0",i);
	    break;
    }
    return 0.;
}

inline void ETruth::SetTrueTOAImpact( Int_t i, Float_t x ) {
    // TrueTOAImpact component by index

    switch(i) {
        case 0:
            fTrueTOAImpactX = x;
            break;
        case 1:
            fTrueTOAImpactY = x;
            break;
        case 2:
            fTrueTOAImpactZ = x;
            break;
        default:
            Error("SetTrueTOAImpact(i)", "bad index (%d)",i);
	    break;
    }
}

inline TVector3 ETruth::GetTrueShowerMaxPos() const {
    return TVector3(fTrueShowerMaxPosX, fTrueShowerMaxPosY, fTrueShowerMaxPosZ);
}

inline void ETruth::SetTrueShowerMaxPos( const TVector3& v ){
    fTrueShowerMaxPosX = v.X();
    fTrueShowerMaxPosY = v.Y();
    fTrueShowerMaxPosZ = v.Z();
}

inline Float_t ETruth::GetTrueShowerMaxPos( Int_t i) const {
    // return TrueShowerMaxPos component by index

    switch(i) {
        case 0:
            return fTrueShowerMaxPosX;
        case 1:
            return fTrueShowerMaxPosY;
        case 2:
            return fTrueShowerMaxPosZ;
        default:
            Error("GetTrueShowerMaxPos(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

inline void ETruth::SetTrueShowerMaxPos( Int_t i, Float_t x ) {
    // TrueShowerMaxPos component by index

    switch(i) {
        case 0:
            fTrueShowerMaxPosX = x;
	    break;
        case 1:
            fTrueShowerMaxPosY = x;
	    break;
        case 2:
            fTrueShowerMaxPosZ = x;
	    break;
        default:
            Error("SetTrueShowerMaxPos(i)", "bad index (%d)",i);
    }
}

#endif  /* __ETRUTH_HH__ */

