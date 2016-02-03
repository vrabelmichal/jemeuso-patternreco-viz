// $Id: ESimpDetPhoton.hh 2620 2006-03-24 16:27:06Z moreggia $
// Author: Sylvain Moreggia   2006/03/21

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ESimpDetPhoton                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __ESIMPDETPHOTON_HH__
#define __ESIMPDETPHOTON_HH__

#include "EPhoton.hh"
#include "EFillable.hh"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// ESimpDetPhoton                                                                 //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class ESimpDetPhoton : public EPhoton {
public:
    
    // ctors
    ESimpDetPhoton();
    ESimpDetPhoton(const EPhoton&);
    ESimpDetPhoton(const ESimpDetPhoton&);
    
    // dtor
    virtual ~ESimpDetPhoton();
    
    virtual void Copy( TObject& ) const;
    virtual void Clear( Option_t* = "");
    
    // getters
    inline Float_t  GetShowerPos( Int_t ) const;                   
    inline UChar_t  GetAtmoHistory() { return fAtmoHistory; }
    inline Int_t    GetFate() const { return fFate;}
    inline TVector3 GetShowerPos() const;

    
    // setters
    inline void SetShowerPos( Int_t,  Float_t );                   
    inline void SetShowerPos( const TVector3& );
    inline void SetHistory( UChar_t h ) { fAtmoHistory = h; }
    inline void SetFate( Int_t f ) { fFate = f;}

private:
    
    Float_t fShowerPosX;       // x position in the atmosphere
    Float_t fShowerPosY;       // y position in the atmosphere
    Float_t fShowerPosZ;       // z position in the atmosphere

    Int_t fAtmoHistory;        // last process undergone in atmosphere
                               // -1: none
                               //  0: direct
                               //  1: reflected
                               //  2: rayleigh scat
                               //  3: clouds scat
                               //  4: aerosols scat
			       
    Int_t fFate;               // fate in detector 
                               // -1: outFoV
                               //  0: alive
                               //  1: absorbed by optics
                               //  2: absorbed by BG3
                               //  3: absorbed by DQE
			       
    Int_t fAtmoNbinter;        // nb of interactions in atmosphere

    SetEVisitable()

    ClassDef(ESimpDetPhoton,1)
};

//_____________________________________________________________________________
inline TVector3 ESimpDetPhoton::GetShowerPos() const {
    // return ShowerPos
    return TVector3( fShowerPosX, fShowerPosY, fShowerPosZ );
}

//_____________________________________________________________________________
inline void ESimpDetPhoton::SetShowerPos( const TVector3& v ) {
    fShowerPosX = v.X();
    fShowerPosY = v.Y();
    fShowerPosZ = v.Z();
}

//_____________________________________________________________________________
inline Float_t ESimpDetPhoton::GetShowerPos( Int_t i) const {
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

//_____________________________________________________________________________
inline void ESimpDetPhoton::SetShowerPos( Int_t i, Float_t x ) {
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


#endif  /* __ESIMPDETPHOTON_HH__ */

