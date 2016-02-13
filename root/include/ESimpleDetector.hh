// $Id: ESimpleDetector.hh 2773 2006-11-17 15:54:35Z moreggia $
// Author: Sylvain Moreggia   2006/03/21

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ESimpleDetector                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __ESIMPLEDETECTOR_HH__
#define __ESIMPLEDETECTOR_HH__

#include "root/include/EFillable.hh"
#include "TROOT.h"
#include "TObject.h"
#include "TRef.h"
#include "TClonesArray.h"
#include "TString.h"
#include "root/include/EDetector.hh"

class ESimpDetPhoton;
class EPhotoElectron;

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// ESimpleDetector                                                                 //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class ESimpleDetector : public TObject, public EFillable {
public:
    
    // ctor
    ESimpleDetector();
    // cpy ctor
    ESimpleDetector(const ESimpleDetector&);
    
    // dtor
    virtual ~ESimpleDetector();

  
    virtual void   Copy( TObject& ) const;
    virtual void   Clear( Option_t* ="");
    virtual void   ClearAndShrink( Option_t* ="" );
    
    inline void    SetPhotonFillingMode( Int_t mode = EDetector::kNoPhotons ) { fPhotonFillingMode = mode; }
    inline UInt_t  GetPhotonFillingMode() { return fPhotonFillingMode; }

    // getters
    inline Bool_t  EventIsTriggered() const {return fEventIsTriggered;}
    inline Float_t GetMeanBgnd() const {return fMeanBgnd;}
    inline Float_t GetTriggerLevel() const {return fTriggerLevel;}
    inline Float_t GetTriggPersistency() const {return fTriggPersistency;}
    inline UInt_t  GetNbPixelOnSide() const {return fNbPixelOnSide;}
    inline Float_t GetPixelSideLength() const {return fPixelSideLength;}
    inline Float_t GetFirstPixelX()   {return fFirstPixelX;}
    inline Float_t GetFirstPixelY()   {return fFirstPixelY;}
    inline UInt_t  GetPixelRowID(UInt_t pixelID) const {return pixelID / fNbPixelOnSide;}
    inline UInt_t  GetPixelColumnID(UInt_t pixelID) const {return pixelID % fNbPixelOnSide;}
    inline Float_t GetFirstTime() const {return fFirstTime; }
    inline Float_t GetLastTime() const {return fLastTime; }
    inline Float_t GetFirstGtuTime() const {return fFirstGTUTime; }
    inline Float_t GetGTUlength() const {return fGTUlength;}
    inline UInt_t  GetNbGTUs() const {return fNbGTUs;}
    inline Int_t   GetNumPhotons() const {return fNumPhotons; }
    inline Int_t   GetNumPhotoElectrons() const {return fNumPhotoElectrons; }


    inline ESimpDetPhoton*    GetPhoton(Int_t index) const;
    inline EPhotoElectron*    GetPhotoElectron(Int_t index) const;
    
    inline static ESimpleDetector* GetCurrent() { return fgCurrent; }
    inline static void SetCurrent(ESimpleDetector *ev) { fgCurrent=ev; }

    
    // setters
    inline void SetEventIsTriggered(Bool_t b)          {fEventIsTriggered = b;}
    inline void SetMeanBgnd(Float_t b)                 {fMeanBgnd = b;}
    inline void SetTriggerLevel(Float_t b)             {fTriggerLevel = b;}
    inline void SetTriggPersistency(UInt_t b)          {fTriggPersistency = b;}
    inline void SetNbPixelOnSide(UInt_t b)             {fNbPixelOnSide = b;}
    inline void SetPixelSideLength(Float_t b)          {fPixelSideLength = b;}
    inline void SetFirstPixelXY(Float_t x,Float_t y)   {fFirstPixelX = x;fFirstPixelY = y;}
    inline void SetFirstTime(Float_t b)                {fFirstTime = b;}
    inline void SetLastTime(Float_t b)                 {fLastTime = b;}
    inline void SetFirstGTUTime(Float_t b)             {fFirstGTUTime = b;}
    inline void SetNbGTUs(UInt_t b)                    {fNbGTUs = b;}
    inline void SetGTUlength(Float_t l)                {fGTUlength = l;}


private:
    
    Bool_t  fEventIsTriggered;      // true if triggered event
    UInt_t  fPhotonFillingMode;     // true to enable photon adders
    
    // input parameters for detector simu
    Float_t    fMeanBgnd;           // mean background (Nadir) in pe-/pixel/GTU
    Float_t    fTriggerLevel;       // nb of background sigma considered for SNR treatment
    UInt_t     fTriggPersistency;   // nb consecutive GTU with adjacent hitted pixels
    UInt_t     fNbPixelOnSide;      // nb of pixels on a side of the square FS
    Float_t    fPixelSideLength;    // pixel side length projected on the MES plane Z=0
    Float_t    fFirstPixelX;        // pixel high left corner X-position projected on the MES plane Z=0
    Float_t    fFirstPixelY;        // pixel high left corner Y-position projected on the MES plane Z=0
    
    Int_t      fNumPhotons;         // number of ESimpDetPhoton in fPhotons array
    Int_t      fNumPhotoElectrons;  // number of EPhotoElectron in fPhotoElectrons array
    Float_t    fFirstTime;          // time of the first photon entering pupil
    Float_t    fLastTime;           // time of the last photon entering pupil
    Float_t    fFirstGTUTime;       // time of first GTU (raising time)
    UInt_t     fNbGTUs;             // nb of GTUs event lasts
    Float_t    fGTUlength;          // GTU length
    
    

    TClonesArray* fPhotons;         // all photons entering the pupil with history in detector
    TClonesArray* fPhotoElectrons;  // photo electrons

    static TClonesArray *fgPhotons;
    static TClonesArray *fgPhotoElectrons;

    static ESimpleDetector* fgCurrent;


    SetEVisitable()
    
    ClassDef(ESimpleDetector,2)
};

//______________________________________________________________________________
inline ESimpDetPhoton* ESimpleDetector::GetPhoton(Int_t index) const {
    return (ESimpDetPhoton*)fPhotons->At(index);
}

//______________________________________________________________________________
inline EPhotoElectron* ESimpleDetector::GetPhotoElectron(Int_t index) const {
    return (EPhotoElectron*)fPhotoElectrons->At(index);
}

#endif  /* __ESIMPLEDETECTOR_HH__ */

