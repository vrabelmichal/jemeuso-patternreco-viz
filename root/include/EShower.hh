// ESAF : Euso Simulation and Analysis Framework
// $Id: EShower.hh 2669 2006-04-12 11:43:13Z thea $
//  created May, 23 2004

#ifndef __ESHOWER_HH_
#define __ESHOWER_HH_

#include "TObject.h"
#include "TClonesArray.h"
#include "TVector3.h"
#include "root/include/EFillable.hh"

class EShowerStep;

// Shower infos
// Shower development infos
class EShower : public TObject, public EFillable {
public:
    EShower();
    EShower(const EShower&);

    virtual ~EShower();
    
    virtual void Copy( TObject& ) const;
    virtual void Clear( Option_t* = "" );
    virtual void   ClearAndShrink( Option_t* ="" );

    // getters
    inline Int_t GetNumSteps() {return fNumSteps;}
    TClonesArray* GetSteps() { return fSteps; }
    inline EShowerStep* GetStep( Int_t );
    inline Float_t  GetEnergy() const { return fEnergy;}
    inline Float_t  GetTheta() const { return fTheta;}
    inline Float_t  GetPhi() const { return fPhi;}
    inline Float_t  GetX1() const { return fX1;}
    inline Float_t  GetElectrEthres() const { return fElectrEthres; }
    inline Float_t  GetDir( Int_t i) const;
    inline TVector3 GetDir() const;
    inline Float_t  GetInitPos( Int_t i) const;
    inline TVector3 GetInitPos() const;
    inline Bool_t   GetHitGround() const { return fHitGround; }

    // setters
    inline void SetEnergy( Float_t t ) {fEnergy = t;}
    inline void SetTheta( Float_t t ) {fTheta = t;}
    inline void SetPhi( Float_t t ) {fPhi = t;}
    inline void SetX1( Float_t t ) {fX1 = t;}
    inline void SetElectrEthres( Float_t t ) { fElectrEthres = t; }
    inline void SetDir( Int_t, Float_t );
    inline void SetDir( const TVector3& );
    inline void SetInitPos( const TVector3& );
    inline void SetInitPos( Int_t, Float_t );
    inline void SetHitGround( Bool_t h ) { fHitGround = h; }

    static inline EShower* GetCurrent() { return fgCurrent; }
    static inline void SetCurrent( EShower* sh ) { fgCurrent = sh; } 
    

private:
    Float_t fEnergy;          // UHECR energy
    Float_t fTheta;           // UHECR Theta
    Float_t fPhi;             // UHECR Phi
    Float_t fX1;              // UHECR first interaction depth
    Float_t fElectrEthres;    // Energy Threshold of electrons in GeV
    Float_t fDirX;            // Direction versor in MES of the track axis
    Float_t fDirY;            // Direction versor in MES of the track axis
    Float_t fDirZ;            // Direction versor in MES of the track axis
    Float_t fInitPosX;        // first interaction point (3D coord, meters) in MES
    Float_t fInitPosY;        // first interaction point (3D coord, meters) in MES
    Float_t fInitPosZ;        // first interaction point (3D coord, meters) in MES
    Bool_t  fHitGround;       // kTRUE is the track can hit the Ground in EUSO FoV, kFALSE otherwise


    Int_t fNumSteps;          // size of fSteps array
    TClonesArray *fSteps;     //

    Bool_t fCopy;             // not necessary any more, kept for compatbility

    static EShower* fgCurrent; 

    SetEVisitable()

    ClassDef(EShower,1)
};

inline EShowerStep* EShower::GetStep( Int_t i ) {
    return (EShowerStep*)fSteps->At(i);
}
 
inline TVector3 EShower::GetDir() const {
    // return Dir
    return TVector3( fDirX, fDirY, fDirZ );
}

inline TVector3 EShower::GetInitPos() const {
    // return InitPos
    return TVector3( fInitPosX, fInitPosY, fInitPosZ );
}

inline Float_t EShower::GetDir( Int_t i) const {
    // return Dir component by index

    switch(i) {
        case 0:
            return fDirX;
        case 1:
            return fDirY;
        case 2:
            return fDirZ;
        default:
            Error("GetDir(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

inline Float_t EShower::GetInitPos( Int_t i) const {
    // return InitPos component by index

    switch(i) {
        case 0:
            return fInitPosX;
        case 1:
            return fInitPosY;
        case 2:
            return fInitPosZ;
        default:
            Error("GetInitPos(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

inline void EShower::SetDir( const TVector3& v ) {
    fDirX = v.X();
    fDirY = v.Y();
    fDirZ = v.Z();
}

inline void EShower::SetInitPos( const TVector3& v ) {
    fInitPosX = v.X();
    fInitPosY = v.Y();
    fInitPosZ = v.Z();
}

inline void EShower::SetDir( Int_t i, Float_t x ) {
    // Dir component by index

    switch(i) {
        case 0:
            fDirX = x;
        case 1:
            fDirY = x;
        case 2:
            fDirZ = x;
        default:
            Error("SetDir(i)", "bad index (%d)",i);
    }
}

inline void EShower::SetInitPos( Int_t i, Float_t x ) {
    // InitPos component by index

    switch(i) {
        case 0:
            fInitPosX = x;
        case 1:
            fInitPosY = x;
        case 2:
            fInitPosZ = x;
        default:
            Error("SetInitPos(i)", "bad index (%d)",i);
    }
}

#endif  /* __ESHOWER_HH_ */

