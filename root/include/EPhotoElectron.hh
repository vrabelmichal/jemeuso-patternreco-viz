// $Id: EPhotoElectron.hh 2878 2011-04-28 13:15:36Z naumov $
// Author: Sylvain Moreggia   2006/03/21

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EPhotoElectron                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __EPHOTOELECTRON_HH__
#define __EPHOTOELECTRON_HH__

#include "TObject.h"
#include "root/include/EFillable.hh"
#include "TVector3.h"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EPhotoElectron                                                                 //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class EPhotoElectron : public TObject {
public:

    // ctors
    EPhotoElectron();
    EPhotoElectron(const EPhotoElectron&);
    
    // dtor
    virtual ~EPhotoElectron();

    virtual void Copy( TObject& ) const;
    virtual void Clear( Option_t* = "");
    
    // getters
    inline UChar_t  GetType()               const {return fType;}
    inline UInt_t   GetPixelID()            const {return fPixelID;}
    inline UInt_t   GetDist2ShiftToShowPt() const {return fDist2ShiftToShowPt;}
    inline Float_t  GetTime()               const {return fTime;}
    inline Float_t  GetSNR()                const {return fSNR;}
    inline Bool_t   IsTriggered()           const {return fTriggered;}
    inline Float_t  GetWl()                 const {return fWl;}
    inline Float_t  GetShowerAge()          const {return fShowerAge;}
    inline TVector3 GetAtmoPos()            const;
    inline Float_t  GetAtmoPos(Int_t)       const;
    inline Int_t    GetAtmoHistory()        const {return fAtmoHistory;}
    inline Int_t    GetAtmoNbinter()        const {return fAtmoNbinter;}
    
    // setters
    inline void SetType(UChar_t t)                       {fType = t;}
    inline void SetPixelID(UInt_t id)                    {fPixelID = id;}
    inline void SetDist2ShiftToShowPt(UInt_t dist2shift) {fDist2ShiftToShowPt = dist2shift;}
    inline void SetTime(Float_t t)                       {fTime = t;}
    inline void SetSNR(Float_t snr)                      {fSNR = snr;}
    inline void Triggered(Bool_t trig = kTRUE)           {fTriggered = trig;}
    inline void SetWl(Float_t wl)                        {fWl = wl;}
    inline void SetShowerAge(Float_t age)                        {fShowerAge = age;}
    inline void SetAtmoPos(const TVector3& pos);
    inline void SetAtmoPos(Int_t,Float_t);
    inline void SetAtmoHistory(Int_t h)                  {fAtmoHistory = h;}
    inline void SetAtmoNbinter(Int_t nb)                 {fAtmoNbinter = nb;}
    
    
private:

    UChar_t fType;                  // 0 : fluo, 1 : ckov, 2 : bgnd
    UInt_t  fPixelID;
    UInt_t  fDist2ShiftToShowPt;    // Squared distance (nb of pixels) to shower point
    Float_t fTime;
    Float_t fSNR;
    Bool_t  fTriggered;
    
    // parent photon related infos
    Float_t     fWl;
    Float_t     fShowerAge;
    Float_t     fAtmoPosX;
    Float_t     fAtmoPosY;
    Float_t     fAtmoPosZ;
    Int_t       fAtmoHistory;   // last interaction in atmosphere (0: direct, 1: reflected, 2: rayleigh, 3: cloud, 4: aerosol)
    Int_t       fAtmoNbinter;   // nb of interactions in atmosphere
    
    SetEVisitable()

    ClassDef(EPhotoElectron,2)
};


//_____________________________________________________________________________
inline TVector3 EPhotoElectron::GetAtmoPos() const {
    // return fAtmoPos
    return TVector3( fAtmoPosX, fAtmoPosY, fAtmoPosZ );
}

//_____________________________________________________________________________
inline void EPhotoElectron::SetAtmoPos( const TVector3& v ) {
    fAtmoPosX = v.X();
    fAtmoPosY = v.Y();
    fAtmoPosZ = v.Z();
}

//_____________________________________________________________________________
inline Float_t EPhotoElectron::GetAtmoPos( Int_t i) const {
    // return fAtmoPos component by index

    switch(i) {
        case 0:
            return fAtmoPosX;
        case 1:
            return fAtmoPosY;
        case 2:
            return fAtmoPosZ;
        default:
            Error("GetAtmoPos(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

//_____________________________________________________________________________
inline void EPhotoElectron::SetAtmoPos( Int_t i, Float_t x ) {
    // fAtmoPos component by index

    switch(i) {
        case 0:
            fAtmoPosX = x;
        case 1:
            fAtmoPosY = x;
        case 2:
            fAtmoPosZ = x;
        default:
            Error("SetAtmoPos(i)", "bad index (%d)",i);
    }
}



#endif  /* __EPHOTOELECTRON_HH__ */

