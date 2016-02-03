// ESAF : Euso Simulation and Analysis Framework
// $Id: EAnglePixelMap.hh 2498 2006-02-22 12:57:29Z thea $
// Author: A.Thea

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EAnglePixelMap                                                       *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/

#ifndef __EANGLEPIXELMAP_HH__
#define __EANGLEPIXELMAP_HH__

#include "TObject.h"
#include "ERunParsFiller.hh"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EAnglePixelMap                                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

class EAnglePixelMap : public TObject {
public:
    EAnglePixelMap();
    EAnglePixelMap( Int_t );
    EAnglePixelMap( const EAnglePixelMap& );

    virtual ~EAnglePixelMap();

    virtual void Clear( Option_t* = "" );
    virtual void Copy( TObject& ) const;
    
    // getters
    inline       Int_t    GetNumPixels() const { return fNumPixels; }
    inline const Float_t* GetThetaFOV() const { return fThetaFOV; }
    inline const Float_t* GetSigmaThetaFOV() const { return fSigmaThetaFOV; }
    inline const Float_t* GetPhiFOV() const { return fPhiFOV; }
    inline const Float_t* GetSigmaPhiFOV() const { return fSigmaPhiFOV; }
    inline       Float_t  GetSigmaThetaFOV( Int_t ) const;
    inline       Float_t  GetThetaFOV( Int_t ) const;
    inline       Float_t  GetPhiFOV( Int_t ) const;
    inline       Float_t  GetSigmaPhiFOV( Int_t ) const;

    // setters
    inline void SetNumPixels( Int_t n ) { Resize(n); }
    inline void SetThetaFOV( Float_t, Int_t );
    inline void SetSigmaThetaFOV( Float_t, Int_t );
    inline void SetPhiFOV( Float_t, Int_t );
    inline void SetSigmaPhiFOV( Float_t, Int_t );
    Bool_t IsValid( Int_t ) const;
    
    ClassDef(EAnglePixelMap,1)

private:
    Int_t Resize( Int_t );      // resize the map

    Int_t fNumPixels;           // number of pixels in the map

    Float_t *fThetaFOV;         //[fNumPixels] theta in FOV 
    Float_t *fSigmaThetaFOV;    //[fNumPixels] sigma theta in FOV
    Float_t *fPhiFOV;           //[fNumPixels] phi in FOV
    Float_t *fSigmaPhiFOV;      //[fNumPixels] sigma phi in FOV

    ERunParsVisitable()
};

inline Bool_t EAnglePixelMap::IsValid( Int_t uid )  const {
    return !( uid < 1 || uid > GetNumPixels() );
}

inline Float_t EAnglePixelMap::GetThetaFOV( Int_t i ) const {
    if ( IsValid( i ) )
        return fThetaFOV[i-1];
    else 
        Error("GetThetaFOV(i)","bad index (%d) returning 0",i);
    return 0.;
}

inline Float_t EAnglePixelMap::GetSigmaThetaFOV( Int_t i ) const {
    if ( IsValid( i ) )
        return fSigmaThetaFOV[i-1];
    else 
        Error("GetSigmaThetaFOV(i)","bad index (%d) returning 0",i);
    return 0.;
}

inline Float_t EAnglePixelMap::GetPhiFOV( Int_t i ) const {
    if ( IsValid( i ) )
        return fPhiFOV[i-1];
    else 
        Error("GetPhiFOV(i)","bad index (%d) returning 0",i);
    return 0.;
}

inline Float_t EAnglePixelMap::GetSigmaPhiFOV( Int_t i ) const {
    if ( IsValid( i ) )
        return fSigmaPhiFOV[i-1];
    else 
        Error("GetSigmaPhiFOV(i)","bad index (%d) returning 0",i);
    return 0.;
}

inline void EAnglePixelMap::SetThetaFOV( Float_t th, Int_t i) { 
    if ( !IsValid( i ) ) {
        Error("SetThetaFOV(i)","bad index (%d) returning 0",i);
        return;
    }

    fThetaFOV[i] = th;

}

inline void EAnglePixelMap::SetSigmaThetaFOV( Float_t sth, Int_t i) { 
    if ( !IsValid( i ) ) {
        Error("SetSigmaThetaFOV(i)","bad index (%d) returning 0",i);
        return;
    }

    fSigmaThetaFOV[i] = sth;

}

inline void EAnglePixelMap::SetPhiFOV( Float_t phi, Int_t i) { 
    if ( !IsValid( i ) ) {
        Error("SetPhiFOV(i)","bad index (%d) returning 0",i);
        return;
    }

    fPhiFOV[i] = phi;

}

inline void EAnglePixelMap::SetSigmaPhiFOV( Float_t sphi, Int_t i) { 
    if ( !IsValid( i ) ) {
        Error("SetSigmaPhiFOV(i)","bad index (%d) returning 0",i);
        return;
    }

    fSigmaPhiFOV[i] = sphi;

}
#endif  /* __EANGLEPIXELMAP_HH__ */

