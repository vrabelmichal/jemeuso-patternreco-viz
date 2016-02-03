// ESAF : Euso Simulation and Analysis Framework
// $Id: EShowerStep.hh 860 2004-06-30 20:06:27Z thea $
// A.Thea created Jun,  9 2004

#ifndef __ESHOWERSTEP_HH_
#define __ESHOWERSTEP_HH_

#include "TObject.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TVector3.h"

/*******************************************************************************
 *
 * EShowerStep: class description
 * 
 ******************************************************************************/

class EShowerStep : public TObject {
public:
    EShowerStep();

    virtual ~EShowerStep();

    virtual void Clear( Option_t* = "" );


    //getters
    inline Float_t GetXi() const { return fXi; }
    inline Float_t GetXf() const { return fXf; }
    inline Float_t GetPosi( Int_t ) const;
    inline TVector3 GetPosi() const;
    inline Float_t GetPosf( Int_t ) const;
    inline TVector3 GetPosf() const;
    inline Float_t GetTimei() const { return fTimei; }
    inline Float_t GetTimef() const { return fTimef; }
    inline Float_t GetAgei() const { return fAgei; }
    inline Float_t GetAgef() const { return fAgef; }
    inline Float_t GetNumElectrons() const { return fNumElectrons; }

    // additional information , could be filled or NULL 
    inline Float_t GetNumCharged() { return  fNumCharged ;}
    inline Float_t GetEnergyLoss() { return fEnergyLoss; }
    inline Float_t GetNumCherenkov() { return fNumCherenkov; }
    
    //setters
    inline void SetXi( Float_t xi ) { fXi = xi; }
    inline void SetXf( Float_t xf ) { fXf = xf; }
    inline void SetPosi( const TVector3& );
    inline void SetPosi( Int_t, Float_t );
    inline void SetPosf( const TVector3& );
    inline void SetPosf( Int_t, Float_t );
    inline void SetTimei( Float_t ti ) { fTimei = ti; }
    inline void SetTimef( Float_t tf ) { fTimef = tf; }
    inline void SetAgei( Float_t ai ) { fAgei = ai; }
    inline void SetAgef( Float_t af ) { fAgef = af; }
    inline void SetNumElectrons( Float_t ne ) { fNumElectrons = ne; }

    inline void SetNumCharged( Float_t nc ) { fNumCharged = nc; }
    inline void SetEnergyLoss( Float_t el ) { fEnergyLoss = el; }
    inline void SetNumCherenkov( Float_t nch ) { fNumCherenkov = nch; }
    
    ClassDef(EShowerStep,1)
        
private:

    // information always present
    Float_t fXi;                 // Slant Depth (g/cm^2) of the first point of the step
    Float_t fXf;                 // Slant Depth (g/cm^2) of the last point of the step
    Float_t fPosiX;              // 3D coordinates in MES of the first point of the step
    Float_t fPosiY;              // 3D coordinates in MES of the first point of the step
    Float_t fPosiZ;              // 3D coordinates in MES of the first point of the step
    Float_t fPosfX;              // 3D coordinates in MES of the last point of the step  
    Float_t fPosfY;              // 3D coordinates in MES of the last point of the step  
    Float_t fPosfZ;              // 3D coordinates in MES of the last point of the step  
    Float_t fTimei;              // Time in microsecond of the passage of shower axis in fXYZi
    Float_t fTimef;              // Time in microsecond of the passage of shower axis in fXYZf
    Float_t fAgei;               // age of the shower at fPosi
    Float_t fAgef;               // age of the shower at fPosf
    Float_t fNumElectrons;       // Number of electrons at (fXf+fXi)/2

    // additional information , could be filled or NULL 
    Float_t fNumCharged;         // Number of charged part. at (fXf+fXi)/2
    Float_t fEnergyLoss;         // Energy (GeV) loss by ionization during the Step
    Float_t fNumCherenkov;       // Number of Cherenov photons produced in the Step

    TH2F    *fEnergyAngle;
    // histogram of energy and polar angular distribution of fNelectrons
    
    TH2F    *fRadPhiElectrons;
    // histogram of Electron radial and phi distribution along axis (phi=0 is
    // the direction perpendicular to the track and  pointing versus the higher
    // density atmospheric region) 
    
    TH2F    *fRadDTimeElectrons;
    // histogram of Radial and Delta-Time respect to axis Time for fNumElectrons

    TH2F    *fRadPhiEnergyLoss;
    // histogram of Energy loss radial and phi distribution along axis (phi=0
    // is the direction perpendicular to the track and  pointing versus the
    // higher density atmospheric region)
    
    TH1F    *fAngleCherenkov;
    // histogram of polar angular distribution of Cherenkov photons fNcherenkov  

};

inline void EShowerStep::SetPosi( const TVector3& v ) {
    fPosiX = v.X();
    fPosiY = v.Y();
    fPosiZ = v.Z();
}

inline void EShowerStep::SetPosf( const TVector3& v ) {
    fPosfX = v.X();
    fPosfY = v.Y();
    fPosfZ = v.Z();
}

inline TVector3 EShowerStep::GetPosi() const {
    // return Pos
    return TVector3( fPosiX, fPosiY, fPosiZ );
}

inline TVector3 EShowerStep::GetPosf() const {
    // return Pos
    return TVector3( fPosfX, fPosfY, fPosfZ );
}

inline Float_t EShowerStep::GetPosi( Int_t i) const {
    // return Posi component by index

    switch(i) {
        case 0:
            return fPosiX;
        case 1:
            return fPosiY;
        case 2:
            return fPosiZ;
        default:
            Error("GetPosf(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

inline Float_t EShowerStep::GetPosf( Int_t i) const {
    // return Posf component by index

    switch(i) {
        case 0:
            return fPosfX;
        case 1:
            return fPosfY;
        case 2:
            return fPosfZ;
        default:
            Error("GetPosf(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

inline void EShowerStep::SetPosi( Int_t i, Float_t x ) {
    // Posi component by index

    switch(i) {
        case 0:
            fPosiX = x;
        case 1:
            fPosiY = x;
        case 2:
            fPosiZ = x;
        default:
            Error("SetPosi(i)", "bad index (%d)",i);
    }
}

inline void EShowerStep::SetPosf( Int_t i, Float_t x ) {
    // Posf component by index

    switch(i) {
        case 0:
            fPosfX = x;
        case 1:
            fPosfY = x;
        case 2:
            fPosfZ = x;
        default:
            Error("SetPosf(i)", "bad index (%d)",i);
    }
}

#endif  /* __ESHOWERSTEP_HH_ */
