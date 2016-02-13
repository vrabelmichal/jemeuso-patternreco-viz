// ESAF : Euso Simulation and Analysis Framework
// $Id: EPhoton.hh 2498 2006-02-22 12:57:29Z thea $
// Author: A.Thea

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EPhoton                                                              *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/

#ifndef __EPHOTON_HH__
#define __EPHOTON_HH__

#include "TObject.h"
#include "TVector3.h"

#include "root/include/EFillable.hh"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EPhoton                                                                    //
//                                                                            //
//   General Photon class                                                     //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

class EPhoton : public TObject {
public:
    EPhoton();
    EPhoton(const EPhoton&);
    
    virtual ~EPhoton();
    
    virtual void Copy( TObject& ) const;
    virtual void Clear( Option_t* = "");

    // getters
    inline UChar_t  GetType() const { return fType;}
    inline Float_t  GetTheta() const { return fTheta;}
    inline Float_t  GetPhi() const { return fPhi;}
    inline Float_t  GetLambda() const { return fLambda;}
    inline Float_t  GetTime() const { return fTime;}
    inline Float_t  GetPos( Int_t ) const;

    // setters
    inline void SetType( UInt_t type ) { fType = type; }
    inline void SetTheta( Float_t th ) { fTheta = th;}
    inline void SetPhi( Float_t ph ) { fPhi = ph; }
    inline void SetLambda( Float_t wl ) { fLambda = wl; }
    inline void SetTime( Float_t t ) { fTime = t;}
    inline void SetPos( Int_t , Float_t );
    inline void SetPos( const TVector3& );

    inline TVector3 GetPos() const;

protected:

        
    UChar_t   fType;           // photon type
    Float_t fTheta;            // photon direction at pupil
    Float_t fPhi;              //   "       "      "    " 
    Float_t fLambda;           // photon wave length
    Float_t fTime;             // time at pupil

    Float_t fPosX;             // x coord. of last known position of the ph 
    Float_t fPosY;             // y coord. of last known position of the ph 
    Float_t fPosZ;             // z coord. of last known position of the ph 

    SetEVisitable()

    ClassDef(EPhoton,1)

};

inline TVector3 EPhoton::GetPos() const {
    // return Pos
    return TVector3( fPosX, fPosY, fPosZ );
}

inline void EPhoton::SetPos( const TVector3& v ){
    fPosX = v.X();
    fPosY = v.Y();
    fPosZ = v.Z();
}

inline Float_t EPhoton::GetPos( Int_t i) const {
    // return Pos component by index

    switch(i) {
        case 0:
            return fPosX;
        case 1:
            return fPosY;
        case 2:
            return fPosZ;
        default:
            Error("GetPos(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

inline void EPhoton::SetPos( Int_t i, Float_t x ) {
    // Pos component by index

    switch(i) {
        case 0:
            fPosX = x;
        case 1:
            fPosY = x;
        case 2:
            fPosZ = x;
        default:
            Error("SetPos(i)", "bad index (%d)",i);
    }
}

#endif  /* __EPHOTON_HH__ */

