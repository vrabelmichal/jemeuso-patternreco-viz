// ESAF : Euso Simulation and Analysis Framework
// $Id: EDetector.hh 2648 2006-03-31 16:04:00Z thea $
// Author: A.Thea

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EDetector                                                            *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/

#ifndef __EDETECTOR_HH__
#define __EDETECTOR_HH__

#include "TROOT.h"
#include "TObject.h"
#include "TRef.h"
#include "TClonesArray.h"
#include "TString.h"

#include "EFillable.hh"

#include "ERunParameters.hh"
#include "EElectronics.hh"
#include "EDetStatus.hh"

class EDetPhoton;
class EMacroCellHit;
class EMacroCell;
class EFee;
class EAFee;

class ERunParameters;

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EDetector                                                                  //
//                                                                            //
// Simu Event Object dedicated holding all the data about the detector        //
// simulation                                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

class EDetector : public TObject, public EFillable { 
public:
    EDetector();
    EDetector(const EDetector&);
    virtual ~EDetector();
  
    virtual void   Copy( TObject& ) const;
    virtual void   Clear( Option_t* ="");
    virtual void   Print(Option_t* option) const;
    virtual void   ClearAndShrink( Option_t* ="" );
    
    inline void    SetPhotonFillingMode( Int_t mode = kAllPhotons ) { fPhotonFillingMode = mode; }
    inline UInt_t  GetPhotonFillingMode() { return fPhotonFillingMode; }

    inline void    SetNightGlowFillable( Bool_t e = kTRUE ) { fNightGlowFillable = e; }
    inline Bool_t  IsNightGlowFillable() { return fNightGlowFillable; }

    inline void    SetRunPars( ERunParameters* );
    inline ERunParameters* RunPars();
    // getters
    inline const   EElectronics* GetElectronics() const {return &fElectronics;}
    inline const   EDetStatus* GetStatus() const { return &fStatus; }
  
    inline Int_t   GetNumPhotons() const {return fNumPhotons; }
    inline Int_t   GetNumCellHits() const {return fNumCellHits; }
    inline Int_t   GetNumFee() const {return fNumFee; }
    inline Int_t   GetNumAFee() const {return fNumAFee; }
    inline Int_t   GetNumCells() const {return fNumCells; }
    inline Float_t GetFirstTime() const {return fFirstTime; }
    inline Float_t GetLastTime() const {return fLastTime; }
    inline Float_t GetFirstGtuTime() const {return fFirstTime; }

    inline EDetPhoton*    GetPhoton(Int_t index) const;
    inline EMacroCellHit* GetMacroCellHit(Int_t index) const;
    inline EFee*          GetFee(Int_t index) const;
    inline EAFee*         GetAFee(Int_t index) const;
    inline EMacroCell*    GetMacroCell(Int_t index) const;

    enum  EPhotonFillingMode {
        kNoPhotons = 0,
        kMadeSignalOnly,
        kAllPhotons
    };

private:
    
    UInt_t  fPhotonFillingMode;   // true to enable photon adders
    Bool_t fNightGlowFillable;    // true to enable ng hits adders

    TRef          fRunPars;       // pointer to run parameters
    EElectronics  fElectronics;   // euso detector electronics status
    EDetStatus    fStatus;        // a summary of the content of the detector
    
    Int_t         fNumPhotons;    // number of EDetPhoton in fPhotons array
    Int_t         fNumCellHits;   // number of EMacroCellHit in fMacroCellHits array
    Int_t         fNumFee;        // number of EFee objects in fFee
    Int_t         fNumAFee;       // number of EAFee objects in fAFee
    Int_t         fNumCells;      // number of EMacroCell objects 
    Float_t       fFirstTime;     // time of the first photon entering pupil
    Float_t       fLastTime;      // time of the last photon entering pupil

    TClonesArray* fPhotons;       // all photons entering the pupil with history in detector
    TClonesArray* fMacroCellHits; // macroCell hit data 
    TClonesArray* fFee;           // front end chip data (digital+full analog if present)
    TClonesArray* fAFee;          // analog specific data (last dynode + trigger info if any)
    TClonesArray* fMacroCell;     // data for each macroCell with activity

    SetEVisitable()
    
    ClassDef(EDetector,5)
};

inline void EDetector::SetRunPars( ERunParameters* r) {
    fRunPars = r;
}

inline ERunParameters* EDetector::RunPars() {
    return (ERunParameters*)fRunPars.GetObject();
}

inline EDetPhoton* EDetector::GetPhoton(Int_t index)  const{
    return (EDetPhoton*)fPhotons->At(index);
}

inline EMacroCellHit* EDetector::GetMacroCellHit(Int_t index) const {
    return (EMacroCellHit*)fMacroCellHits->At(index);
}

inline EFee* EDetector::GetFee(Int_t index) const {
    return (EFee*)fFee->At(index);
}

inline EAFee* EDetector::GetAFee(Int_t index) const {
    return (EAFee*)fAFee->At(index);
}
inline EMacroCell* EDetector::GetMacroCell(Int_t index) const {
    return (EMacroCell*)fMacroCell->At(index);
}

#endif  /* __EDETECTOR_HH__ */
