// ESAF : Euso Simulation and Analysis Framework
// $Id: ERunParameters.hh 2800 2008-02-11 14:16:18Z naumov $
// M. Pallavicini, A. Thea created Sep, 19 2003

#ifndef __ERUNPARAMETERS_HH_
#define __ERUNPARAMETERS_HH_

#include <TObject.h>
#include <TClonesArray.h>
#include <TVector3.h>
#include <TArrayF.h>

#include "root/include/ERunParsFiller.hh"
#include "root/include/EPmtData.hh"
#include "root/include/EPmtGeo.hh"
#include "root/include/EAnglePixelMap.hh"
#include "root/include/ETriggPars.hh"
#include "root/include/Etypes.hh"
#include <TMath.h>

enum ESquareCorner { kTopLeftCorner     = 0,
                     kTopRightCorner    = 1,
                     kBottomRightCorner = 2,
                     kBottomLeftCorner  = 3 
};

using namespace TMath;

// ERunParameters: container of the Detector configuration
class ERunParameters : public TObject { 
public:
    ERunParameters();
    ERunParameters( const ERunParameters& );

    virtual ~ERunParameters();

//     inline static ERunParameters* GetCurrent() { return fgCurrent; }
//     inline static void SetCurrent(ERunParameters *rp) { fgCurrent=rp; }
    // set current instance
    
      virtual void Copy( TObject& ) const ;
      virtual void Clear( Option_t* ="" );
    
    inline const TClonesArray* GetPmts() const { return fPmts; }
    inline const EPmtData& GetPmtData() const { return fPmtData; }
    inline const EAnglePixelMap& GetPixelMap() const { return fAnglePixelMap; }

           Float_t GetNightGlowRate(Int_t feid) const;
      inline Float_t GetMinNightGlowRate() const { return MinElement(fChipNightGlowRates.GetSize(),fChipNightGlowRates.GetArray()); }
      inline Float_t GetMaxNightGlowRate() const { return MaxElement(fChipNightGlowRates.GetSize(),fChipNightGlowRates.GetArray()); }
           Float_t GetNightGlowRateByUId(Int_t uid) const;
      inline Int_t GetNumPmts() const { return fNumPmts; }
    const EPmtGeo* GetPmtGeo(Int_t id) const;
    const EPmtGeo* GetPmtGeoByUId(Int_t uid) const;
             Int_t ElementaryCell( Int_t uid ) const;
             Int_t FrontEndChip( Int_t uid ) const;
       inline void Fill( ERunParsFiller& f) { f.Fill( this ); }
            Bool_t IsInsidePixel(Int_t uid, const TVector2&) const; 
     inline Bool_t IsValidPmt( Int_t id ) const;
             Int_t MacroCell( Int_t uid ) const;
          TVector3 PixelCenter( Int_t uid) const;
          TVector3 PixelCorner( Int_t uid, Int_t corner ) const;
             Int_t Pmt( Int_t uid ) const;
          TVector3 PmtCorner( Int_t pmtid, Int_t corner ) const;
    
    const ETriggPars* GetTriggPars( const char* name ) const;
    const ETriggPars* GetTriggPars( ETriggerTypeIdentifier id ) const;
    
    void DrawFocalSurface();
private:
    
             Int_t fNumPmts;            // number of photomultipliers

     TClonesArray* fPmts;               //-> description of the pmts

           TArrayF fChipNightGlowRates; // FE nightglow rates in p.e./microsec per pixel
    
          EPmtData fPmtData;            // common parameters of the pmts
    EAnglePixelMap fAnglePixelMap;      // map angle pixel
            TList* fTriggPars;

    ClassDef(ERunParameters,2) 

    ERunParsVisitable()
};

inline Bool_t ERunParameters::IsValidPmt( Int_t id ) const{
    return (id > 0 && id <= fNumPmts);
}
#endif
