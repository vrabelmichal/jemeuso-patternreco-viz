// ESAF : Euso Simulation and Analysis Framework
// $Id: EPmtGeo.hh 2044 2005-07-17 01:37:58Z thea $
//  created May, 24 2004

#ifndef __EPMTGEO_HH_
#define __EPMTGEO_HH_

#include "TObject.h"
#include "TVector3.h"

#include "root/include/ERunParsFiller.hh"

// EPmtGeo
// Geographical information of each pmt
class EPmtGeo: public TObject {
public:
    EPmtGeo();
    EPmtGeo( const EPmtGeo& );

    virtual ~EPmtGeo();

    virtual void Copy( TObject& ) const;
    virtual void Clear( Option_t* = "");

    // getters
    inline Int_t    GetStartUniqueId() const { return fStartUId; }
    inline Int_t    GetLastUniqueId() const { return fLastUId; }
    inline Int_t    GetFee() const { return fFee; }
    inline Int_t    GetEC() const { return fEC; }                  
    inline Int_t    GetMC() const { return fMC; }
           Float_t  GetCenter(Int_t) const;
           Float_t  GetNorm(Int_t) const;
           Float_t  GetYAxis(Int_t) const;
           Float_t  GetXAxis(Int_t) const;
    inline TVector3 GetCenter() const;
    inline TVector3 GetNorm() const;
    inline TVector3 GetYAxis() const;
    inline TVector3 GetXAxis() const;
    
    // setters
    inline void SetStartUniqueId( Int_t uid ) { fStartUId = uid; }
    inline void SetLastUniqueId( Int_t uid ) { fLastUId = uid; }
    inline void SetFee( Int_t fe ) { fFee = fe; }
    inline void SetEC( Int_t ec ) { fEC = ec; }                  
    inline void SetMC( Int_t mc ) { fMC = mc; }
    inline void SetCenter( const Float_t* );
    inline void SetNorm( const Float_t* );
    inline void SetYAxis( const Float_t* );
    inline void SetCenter( const TVector3& );
    inline void SetNorm( const TVector3& );
    inline void SetYAxis( const TVector3& );

private:
    Int_t fStartUId;                // UId of the first pixel
    Int_t fLastUId;                 // UId of the last pixel
    Int_t fFee;                     // Fee the pmt belongs to 
    Int_t fEC;                      // EC the pmt belongs to 
    Int_t fMC;                      // MC the pmt belongs to 

    Float_t fCenterX;               // x component of the center of the pmt
    Float_t fCenterY;               // y component of the center of the pmt
    Float_t fCenterZ;               // z component of the center of the pmt

    Float_t fNormX;                 // x component of the normal vector
    Float_t fNormY;                 // y component of the normal vector
    Float_t fNormZ;                 // z component of the normal vector

    Float_t fYAxisX;                // x component of the pmt y axis
    Float_t fYAxisY;                // y component of the pmt y axis
    Float_t fYAxisZ;                // z component of the pmt y axis

    ClassDef(EPmtGeo,1)

    ERunParsVisitable()
};

inline TVector3 EPmtGeo::GetCenter() const {
    return TVector3(fCenterX, fCenterY, fCenterZ);
}

inline TVector3 EPmtGeo::GetNorm() const {
    return TVector3(fNormX, fNormY, fNormZ);
}

inline TVector3 EPmtGeo::GetYAxis() const {
    return TVector3(fYAxisX, fYAxisY, fYAxisZ);
}


inline TVector3 EPmtGeo::GetXAxis() const {
    TVector3 a;
    a.SetX(fYAxisY*fNormZ-fYAxisZ*fNormY);
    a.SetY(fYAxisZ*fNormX-fYAxisX*fNormZ);
    a.SetZ(fYAxisX*fNormY-fYAxisY*fNormX);
    return a;

}

inline void EPmtGeo::SetCenter( const TVector3& v ) {
    fCenterX = v[0];
    fCenterY = v[1];
    fCenterZ = v[2];
}

inline void EPmtGeo::SetNorm( const TVector3& v ) {
    fNormX = v[0];
    fNormY = v[1];
    fNormZ = v[2];
}

inline void EPmtGeo::SetYAxis( const TVector3& v ) {
    fYAxisX = v[0];
    fYAxisY = v[1];
    fYAxisZ = v[2];
}

inline void EPmtGeo::SetCenter( const Float_t* v ) {
    fCenterX = v[0];
    fCenterY = v[1];
    fCenterZ = v[2];
}

inline void EPmtGeo::SetNorm( const Float_t* v ) {
    fNormX = v[0];
    fNormY = v[1];
    fNormZ = v[2];
}

inline void EPmtGeo::SetYAxis( const Float_t* v ) {
    fYAxisX = v[0];
    fYAxisY = v[1];
    fYAxisZ = v[2];
}

#endif  /* __EPMTGEO_HH_ */

