// ESAF : Euso Simulation and Analysis Framework
// $Id: ESinglePhoton.hh 2765 2006-11-15 14:59:23Z moreggia $
// A.Thea created Jun,  9 2004

#ifndef __ESINGLEPHOTON_HH_
#define __ESINGLEPHOTON_HH_

#include "TObject.h"
#include "TVector3.h"
#include <TArrayC.h>

class ESinglePhoton : public TObject {
public:
    ESinglePhoton();

    virtual ~ESinglePhoton();
    
    virtual void Clear( Option_t* ="" );

    //getters
    inline UChar_t GetType() const {return fType;}
    inline UInt_t GetBunchId() const {return fBunchId;}
    inline UChar_t GetHistory() const {return fHistory;}
    inline Char_t GetAllHistory(UInt_t i) const {return fAllHistory[i];}
    inline Bool_t IsAbsorbed() const {return fAbsorbed;}
    inline Bool_t IsCloudAbsorbed() const {return fCloudAbsorbed;}
    inline Bool_t IsOutFoV() const {return fOutFoV;}
    inline Float_t GetDate() const {return fDate;}
    inline Float_t GetShowerAge() const {return fShowerAge;}
    inline Float_t GetTof() const {return fTof;}
    inline Float_t GetWl() const {return fWl;}
    inline Int_t GetNbinter() const {return fNbinter;}
    inline TVector3 GetShowerPos() const;
    inline TVector3 GetPos() const;
    inline TVector3 GetMScatDir() const;
    inline Float_t GetLastTrans(TString type) const;
    
    //setters
    inline void SetType ( UInt_t type ) { fType = type; }
    inline void SetHistory( UInt_t hist ) { fHistory = hist; }
    inline void SetAllHistory(Int_t i, Char_t hist ) { fAllHistory[i] = hist; }
    inline void SetAbsorbed(Bool_t f = true) {fAbsorbed = f;}
    inline void SetCloudAbsorbed(Bool_t f = true) {fCloudAbsorbed = f;}
    inline void SetOutFoV(Bool_t f = true) {fOutFoV = f;}
    inline void SetDate(Float_t d) {fDate = d;}
    inline void SetShowerAge(Float_t d) {fShowerAge = d;}
    inline void SetTof( Float_t tof ) {fTof = tof; }
    inline void SetWl( Float_t wl ) {fWl = wl; }
    inline void SetNbinter ( Int_t nb ) { fNbinter = nb; }
    inline void SetNbMaxInter ( Int_t nb ) {fAllHistory.Set(nb); for(Int_t i=0;i<nb;i++) fAllHistory[i] = 0;}
    inline void SetShowerPos( const TVector3& v );
    inline void SetPos( const TVector3& v );
    inline void SetMScatDir( const TVector3& v );
    inline void SetBunchId(UInt_t id) {fBunchId = id;}
    inline void SetLastTrans( Float_t trans, TString type );


private:

    UChar_t fType;               // photon type
    UInt_t fBunchId;             // id of the bunch that has given this photon
    UChar_t fHistory;            // how photon has been created
                                 // 0 : direct
				 // 1 : reflected
				 // 2 : rayleigh scattered
				 // 3 : clouds scattered
				 // 4 : aerosols scattered
    TArrayC fAllHistory;         // summary of all interactions in atmosphere (all values > 0)
    Bool_t fAbsorbed;            // true if photon has been absorbed during its final transfer to pupil
    Bool_t fCloudAbsorbed;       // true if photon has been cloud absorbed during its final transfer to pupil
    Float_t fLastTotTrans;       // total transmission over the final path to detector
    Float_t fLastRaylTrans;      // Rayleigh transmission over the final path to detector
    Float_t fLastOzoneTrans;     // Ozone transmission over the final path to detector
    Float_t fLastAeroTrans;      // Aerosols transmission over the final path to detector
    Float_t fLastCloudTrans;     // Cloud transmission over the final path to detector
    Bool_t fOutFoV;              // (ONLY a flag : no simu for it) true if entering dir on pupil > FoV
    Float_t fDate;               // date of creation
    Float_t fShowerAge;          // shower age at photon creation
    Float_t fTof;                // time of flight since creation UNTIL PUPIL
    Float_t fWl;                 // wavelength
    Int_t fNbinter;              // number of interactions undergone
    Float_t fShowerPosX;         // X.position of creation
    Float_t fShowerPosY;         // Y.position of creation
    Float_t fShowerPosZ;         // Z.position of creation
    Float_t fPosX;               // last position.X before reaching pupil
    Float_t fPosY;               // last position.Y before reaching pupil
    Float_t fPosZ;               // last position.Z before reaching pupil
    
    // only for MScattAnalysis (MCRadiativeTransfer)
    Float_t fMScatDirX;          // last direction.X before going toward detector
    Float_t fMScatDirY;          // last direction.Y before going toward detector
    Float_t fMScatDirZ;          // last direction.Z before going toward detector
    
    ClassDef(ESinglePhoton,1)

};

//_________________________________________________________________________________________
inline TVector3 ESinglePhoton::GetShowerPos() const {
    TVector3 rtn(fShowerPosX,fShowerPosY,fShowerPosZ);
    return rtn;
}

//_________________________________________________________________________________________
inline void ESinglePhoton::SetShowerPos( const TVector3& v ){
    fShowerPosX = v.X();
    fShowerPosY = v.Y();
    fShowerPosZ = v.Z();
}

//_________________________________________________________________________________________
inline TVector3 ESinglePhoton::GetPos() const {
    TVector3 rtn(fPosX,fPosY,fPosZ);
    return rtn;
}

//_________________________________________________________________________________________
inline TVector3 ESinglePhoton::GetMScatDir() const {
    TVector3 rtn(fMScatDirX,fMScatDirY,fMScatDirZ);
    return rtn;
}

//_________________________________________________________________________________________
inline void ESinglePhoton::SetPos( const TVector3& v ){
    fPosX = v.X();
    fPosY = v.Y();
    fPosZ = v.Z();
} 

//_________________________________________________________________________________________
inline void ESinglePhoton::SetMScatDir( const TVector3& v ){
    fMScatDirX = v.X();
    fMScatDirY = v.Y();
    fMScatDirZ = v.Z();
} 

//_________________________________________________________________________________________
inline void ESinglePhoton::SetLastTrans(Float_t trans, TString type) {
    //
    //
    //
    if(type == "tot")        fLastTotTrans = trans;
    else if(type == "rayl")  fLastRaylTrans = trans;
    else if(type == "ozone") fLastOzoneTrans = trans;
    else if(type == "aero")  fLastAeroTrans = trans;
    else if(type == "cloud") fLastCloudTrans = trans;
    else Fatal("SetLastTrans","Wrong argument = %s",type.Data());
}

//_________________________________________________________________________________________
inline Float_t ESinglePhoton::GetLastTrans(TString type) const {
    //
    //
    //
    Float_t rtn(0.);
    if(type == "tot")        rtn = fLastTotTrans;
    else if(type == "rayl")  rtn = fLastRaylTrans;
    else if(type == "ozone") rtn = fLastOzoneTrans;
    else if(type == "aero")  rtn = fLastAeroTrans;
    else if(type == "cloud") rtn = fLastCloudTrans;
    else Fatal("GetLastTrans","Wrong argument = %s",type.Data());
    return rtn;
}

#endif  /* __ESINGLEPHOTON_HH_ */

