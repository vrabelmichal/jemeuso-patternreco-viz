// ESAF : Euso Simulation and Analysis Framework
// $Id: EDetPhoton.hh 3007 2012-01-11 10:06:56Z fenu $
//  created May, 18 2004

#ifndef __EDETPHOTON_HH__
#define __EDETPHOTON_HH__

#include "EPhoton.hh"
#include "TVector3.h"

#include "EFillable.hh"


class EDetPhoton : public EPhoton {
public:
    EDetPhoton();
    EDetPhoton(const EPhoton&);
    EDetPhoton(const EDetPhoton&);
    
    virtual ~EDetPhoton();
    
    virtual void Copy( TObject& ) const;
    virtual void Clear( Option_t* = "");

    // getters
    inline UShort_t GetStatusBits() const { return fStatusBits; }
    inline Float_t  GetShowerPos( Int_t ) const;           
    inline Float_t  GetShowerAge() const { return fAge; }
    inline UChar_t  GetHistory() { return fHistory; }
    inline Int_t    GetFate() const { return fFate;}
    inline Float_t  GetIdealFocalPos( Int_t ) const;
    inline Int_t    GetFe() const { return fFe;}
    inline Int_t    GetMacroCell() const { return fMacroCell;}
    inline Int_t    GetGtu() const { return fGtu;}
    inline Int_t    GetXCell() const { return fXCell; }
    inline Int_t    GetYCell() const { return fYCell; }
    inline Int_t    GetPixelUID() const { return fPixelUID;}
    inline Int_t    GetSignalId() const { return fSignalId;}
    inline Float_t  GetCharge() const { return fCharge;}
    inline Float_t  GetIPeak() const { return fIPeak;}
    inline Float_t  GetSignalTime() const { return fSignalTime;}

    // setters
    inline void SetShowerPos( Int_t,  Float_t );                   
    inline void SetShowerPos( const TVector3& );
    inline void SetHistory( UChar_t h ) { fHistory = h; }
    inline void SetFate( Int_t f ) { fFate = f;}
    inline void SetShowerAge( Int_t f ) { fAge = f;}
    inline void SetIdealFocalPos( Int_t, Float_t );
    inline void SetIdealFocalPos( const TVector3& );
    inline void SetFe( Int_t fe ) { fFe = fe;}
    inline void SetMacroCell( Int_t mc ) { fMacroCell = mc; }
    inline void SetXCell( Int_t x ) { fXCell = x; }
    inline void SetYCell( Int_t y ) { fYCell = y; }
    inline void SetGtu( Int_t gtu ) { fGtu = gtu; }
    inline void SetPixelUID( Int_t uid ) { fPixelUID = uid; }
    inline void SetSignalId( Int_t id ) { fSignalId = id; }
    inline void SetCharge( Float_t c ) { fCharge = c;}
    inline void SetIPeak( Float_t ip ) { fIPeak = ip; }
    inline void SetSignalTime( Float_t t ) { fSignalTime = t;}

    inline Bool_t  CrossedIFS() const { return (fStatusBits & kCrossedIFS) != 0; }
    inline Bool_t  MadeSignal() const { return (fStatusBits & kMadeSignal) != 0; }
    inline Bool_t  MadeCount() const { return (fStatusBits & kMadeCount) != 0; }
    inline Bool_t  MadeFastOR() const { return (fStatusBits & kMadeFastOR) != 0; }

    // photon status
    inline void SetCrossedIFS() { fStatusBits |= kCrossedIFS; }
    inline void SetMadeSignal() { fStatusBits |= kMadeSignal; }
    inline void SetMadeCount() { fStatusBits |= kMadeCount; }
    inline void SetMadeFastOR() { fStatusBits |= kMadeFastOR; }
    inline void ClearCrossedIFS() { fStatusBits &= ~kCrossedIFS; }
    inline void ClearMadeSignal() { fStatusBits &= ~kMadeSignal; }
    inline void ClearMadeCount() { fStatusBits &= ~kMadeCount; }
    inline void ClearMadeFastOR() { fStatusBits &= ~kMadeFastOR; }

    enum EStatus { 
        kCrossedIFS               = BIT(0),
        kMadeSignal               = BIT(1),
        kMadeCount                = BIT(2),
        kMadeFastOR               = BIT(3)
    };

    inline TVector3 GetShowerPos() const;
    // position in the Shower

    inline TVector3 GetIdealFocalPos() const;
    // coord on ideal FS 
    
      
private:

        
    UShort_t  fStatusBits;     // bits holding photon's status 
    Float_t fShowerPosX;       // x position in the Shower
    Float_t fShowerPosY;       // y position in the Shower
    Float_t fShowerPosZ;       // z position in the Shower
    Float_t fAge;
    // photon's destiny
    Int_t fHistory;            // code of last position of the photon
    Int_t fFate;               // return flag of the module in which photon ends
    Float_t fIdealFocalPosX;   // x coord. on the ideal focal surface
    Float_t fIdealFocalPosY;   // y coord. on the ideal focal surface
    Float_t fIdealFocalPosZ;   // z coord. on the ideal focal surface

    // photon's electronic image
    Int_t fFe;                 // fe chip
    Int_t fMacroCell;          // macrocell number hit

    Int_t fXCell;              // X coordinate in macrocell 
    Int_t fYCell;              // Y coordinate in macrocell
    
    Int_t fGtu;                // gtu number this photon belongs to
    Int_t fPixelUID;           // unique pixel id
    Int_t fSignalId;           // identifier of the PmtSignal object
    Float_t fCharge;           // pmt charge
    Float_t fIPeak;            // peak current at input
    Float_t fSignalTime;       // pmt signal time

    SetEVisitable()

    ClassDef(EDetPhoton,1)

};

inline TVector3 EDetPhoton::GetShowerPos() const {
    // return ShowerPos
    return TVector3( fShowerPosX, fShowerPosY, fShowerPosZ );
}

inline TVector3 EDetPhoton::GetIdealFocalPos() const {
    // return IdealFocalPos
    return TVector3( fIdealFocalPosX, fIdealFocalPosY, fIdealFocalPosZ );
}

inline void EDetPhoton::SetShowerPos( const TVector3& v ) {
    fShowerPosX = v.X();
    fShowerPosY = v.Y();
    fShowerPosZ = v.Z();
}

inline void EDetPhoton::SetIdealFocalPos( const TVector3& v ) {
    fIdealFocalPosX = v.X();
    fIdealFocalPosY = v.Y();
    fIdealFocalPosZ = v.Z();
}

inline Float_t EDetPhoton::GetShowerPos( Int_t i) const {
    // return ShowerPos component by index

    switch(i) {
        case 0:
            return fShowerPosX;
        case 1:
            return fShowerPosY;
        case 2:
            return fShowerPosZ;
        default:
            Error("GetShowerPos(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

inline Float_t EDetPhoton::GetIdealFocalPos( Int_t i) const {
    // return IdealFocalPos component by index

    switch(i) {
        case 0:
            return fIdealFocalPosX;
        case 1:
            return fIdealFocalPosY;
        case 2:
            return fIdealFocalPosZ;
        default:
            Error("GetIdealFocalPos(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

inline void EDetPhoton::SetShowerPos( Int_t i, Float_t x ) {
    // ShowerPos component by index

    switch(i) {
        case 0:
            fShowerPosX = x;
        case 1:
            fShowerPosY = x;
        case 2:
            fShowerPosZ = x;
        default:
            Error("SetShowerPos(i)", "bad index (%d)",i);
    }
}

inline void EDetPhoton::SetIdealFocalPos( Int_t i, Float_t x ) {
    // IdealFocalPos component by index

    switch(i) {
        case 0:
            fIdealFocalPosX = x;
        case 1:
            fIdealFocalPosY = x;
        case 2:
            fIdealFocalPosZ = x;
        default:
            Error("SetIdealFocalPos(i)", "bad index (%d)",i);
    }
}

#endif  /* __EDETPHOTON_HH__ */

