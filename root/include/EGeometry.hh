// $Id: EGeometry.hh 3001 2011-11-22 21:46:43Z mabl $
// Author: Alessandro Thea   2005/11/14

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EGeometry                                                            *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __EGEOMETRY_HH__
#define __EGEOMETRY_HH__

#include "root/include/EFillable.hh"
#include <TRotation.h>
#include <TVector3.h>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EGeometry                                                                  //
//                                                                            //
// <brief class description>                                                  //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

class EGeometry : public EFillable {
public:
    EGeometry();
    virtual ~EGeometry();

    virtual void Clear( Option_t* = "" );

    Float_t GetFoV() const { return fFoV; }

    inline Float_t  GetPos( Int_t ) const;
    inline TVector3 GetPos() const;

    Float_t GetRadius()       const { return fRadius; }
    Float_t GetOpticsRadius() const { return fOpticsRadius; }

    const TRotation& GetRotation() const { return fRotation; }

    void SetXEulerAngles(Float_t phi, Float_t theta, Float_t psi)
                          { fRotation.SetXEulerAngles(phi, theta, psi); }

    void SetFoV( Float_t fov ) { fFoV = fov; }
    void SetRadius( Float_t radius ) { fRadius = radius; }
    void SetOpticsRadius(Float_t radius ) { fOpticsRadius = radius;}
    void SetRotation( const TRotation& rot ) { fRotation = rot; }
    inline void SetPos( Int_t , Float_t );
    inline void SetPos( const TVector3& );

private:

    Float_t fFoV;    // field of view of the telescope
    Float_t fRadius; // radius of the telescope
    Float_t fOpticsRadius; // radius of the entrance pupil (not necessary equal to radius of the telescope)
    Float_t fPosX;   // position in MES, X
    Float_t fPosY;   // position in MES, Y
    Float_t fPosZ;   // position in MES, Z

    TRotation fRotation;  // rotation local->global

    ClassDef(EGeometry,1)
};

inline TVector3 EGeometry::GetPos() const {
    // return Pos
    return TVector3( fPosX, fPosY, fPosZ );
}

inline void EGeometry::SetPos( const TVector3& v ){
    fPosX = v.X();
    fPosY = v.Y();
    fPosZ = v.Z();
}

inline Float_t EGeometry::GetPos( Int_t i) const {
    // return Pos component by index

    switch(i) {
        case 0:
            return fPosX;
            break;
        case 1:
            return fPosY;
            break;
        case 2:
            return fPosZ;
            break;
        default:
            Error("GetPos(i)", "bad index (%d) returning 0",i);
    }
    return 0.;
}

inline void EGeometry::SetPos( Int_t i, Float_t x ) {
    // Pos component by index

    switch(i) {
        case 0:
            fPosX = x;
            break;
        case 1:
            fPosY = x;
            break;
        case 2:
            fPosZ = x;
            break;

        default:
            Error("SetPos(i)", "bad index (%d)",i);
    }
}

#endif  /* __EGEOMETRY_HH__ */


