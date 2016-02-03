// ESAF : Euso Simulation and Analysis Framework
// $Id: EBunchPhotons.hh 2922 2011-06-12 14:21:23Z mabl $
// A.Thea created Jun, 13 2004

#ifndef __EBUNCHPHOTONS_HH_
#define __EBUNCHPHOTONS_HH_

#include "TObject.h"
#include "TRefArray.h"
#include "TVector3.h"
#include "TString.h"

#include "EFillable.hh"
#include "ESinglePhoton.hh"

#include <stdexcept>
#include <iostream>

class EBunchPhotons : public TObject {
public:
    // ctor
    EBunchPhotons();
    EBunchPhotons( const EBunchPhotons& );

    // dtor
    virtual ~EBunchPhotons();

    virtual void Copy( TObject& ) const;
    virtual void Clear(Option_t* ="" );

    inline void AddSingleRef( ESinglePhoton* );
    inline TRefArray *GetSinglesArray() const {return fSingles;}

    // getters
    inline UChar_t GetType() const {return fType;}
    inline UInt_t GetId() const {return fId;}
    inline Float_t GetWeight() const {return fWeight;}
    inline Float_t GetDatei() const {return fDatei;}
    inline Float_t GetDatef() const {return fDatef;}
    inline Float_t GetShowerAge() const {return fShowerAge;}
    inline TVector3 GetShowerPosi() const;
    inline TVector3 GetShowerPosf() const;
    inline TVector3 GetFinalPos() const;
    inline TVector3 GetMeanDir() const;
    inline Float_t GetYield() const {return fYield;}
    inline Int_t GetNumWavelengths() const {return fNumWavelengths;}
    inline const Float_t* GetTable(const char*) const;
    inline UChar_t GetFate() const {return fFate;}
    
    inline Int_t GetNumAll(TString opt = "all") const;
    inline Int_t GetNumDirect(TString opt = "all") const;
    inline Int_t GetNumAirScat(TString opt = "all") const;
    inline Int_t GetNumAeroScat(TString opt = "all") const;
    inline Int_t GetNumCloudScat(TString opt = "all") const;
    inline Int_t GetNumReflected(TString opt = "all") const;

    //setters
    inline void SetType ( UInt_t type ) { fType = type; }
    inline void SetId(UInt_t id) {fId = id;}
    inline void SetDatei( Float_t date) { fDatei = date; }
    inline void SetDatef( Float_t date) { fDatef = date; }
    inline void SetShowerAge( Float_t age) { fShowerAge = age; }
    inline void SetShowerPosi( const TVector3& v );
    inline void SetShowerPosf( const TVector3& v );
    inline void SetFinalPos( const TVector3& v );
    inline void SetMeanDir( const TVector3& v );
    inline void SetWeight( Float_t w) { fWeight = w; }
    inline void SetYield( Float_t y) { fYield = y; }
    inline void SetFate(UChar_t f) {fFate = f;}

//DELETE : for BunchRT simulation only
//inline void SetFinalWeight(Float_t w) {fFinalWeight = w;}

    void SetSpectrum ( Int_t n, const Float_t* lambda, const Float_t* weight );

private:

    UChar_t fType;                                  // Bunch Type
    UInt_t fId;                                     // bunch identity
    Float_t fWeight;                                // bunch weight

//DELETE : for BunchRT simulation only
//Float_t fFinalWeight;

    Float_t fDatei;                                 // date of creation of the first point
    Float_t fDatef;                                 // date of creation of the last point
    Float_t fShowerAge;                             // mean shower age at creation
    
    Float_t fShowerPosiX,fShowerPosiY,fShowerPosiZ; // first point of the bunch at creation
    Float_t fShowerPosfX,fShowerPosfY,fShowerPosfZ; // last point of the bunch at creation
    Float_t fFinalPosX,fFinalPosY,fFinalPosZ;	    // where bunch simulation has stopped
    Float_t fMeanDirX,fMeanDirY,fMeanDirZ;          // mean direction
    
    Float_t fYield;                                 // light yield associated with this bunch
    
    Int_t fNumWavelengths;   // nb of bins in the following spectra
    Float_t *fWlLambda;      // [fNumWavelengths] array of wavelength (for spectrum X-axis bin CENTER) -> fNumWavelengths values
    Float_t *fWlWeight;      // [fNumWavelengths] number of photons at bunch creation
    
    UChar_t fFate;           // fate of the bunch (where it dies in the code)
                             // 0 : initialization value
			     // 1 : not propagated ->    because fluo bunch
			     // 2 : not propagated ->    because too small weight
			     // 3 : not propagated ->    because created underground
                             // 4 : propagated     ->    has reached ground
			     // 5 : propagated     ->    til out of FoV

    TRefArray *fSingles;     // reference to singlephotons coming from this bunch
    
    Int_t fNumFluoDirect;    // nb of direct fluo singles  
    Int_t fNumCkovDirect;    // nb of direct ckov singles  
    Int_t fNumFluoAirScat;   // nb of air scattered fluo singles    
    Int_t fNumCkovAirScat;   // nb of air scattered ckov singles   
    Int_t fNumFluoAeroScat;  // nb of aerosol scattered fluo singles  
    Int_t fNumCkovAeroScat;  // nb of aerosol scattered ckov singles  
    Int_t fNumFluoCloudScat; // nb of cloud scattered fluo singles  
    Int_t fNumCkovCloudScat; // nb of cloud scattered ckov singles   
    Int_t fNumFluoReflected; // nb of ground reflected fluo singles  
    Int_t fNumCkovReflected; // nb of ground reflected ckov singles   
    
    SetEVisitable()

    ClassDef(EBunchPhotons,1)
};




inline TVector3 EBunchPhotons::GetShowerPosi() const {
    TVector3 rtn(fShowerPosiX,fShowerPosiY,fShowerPosiZ);
    return rtn;
}

inline TVector3 EBunchPhotons::GetShowerPosf() const {
    TVector3 rtn(fShowerPosfX,fShowerPosfY,fShowerPosfZ);
    return rtn;
}

inline TVector3 EBunchPhotons::GetFinalPos() const {
    TVector3 rtn(fFinalPosX,fFinalPosY,fFinalPosZ);
    return rtn;
}

inline TVector3 EBunchPhotons::GetMeanDir() const {
    TVector3 rtn(fMeanDirX,fMeanDirY,fMeanDirZ);
    return rtn;
}

inline const Float_t* EBunchPhotons::GetTable(const char* s) const {
    Float_t* rtn = 0;
    
    if(strncmp(s,"lambda",6) == 0) rtn = fWlLambda;
    else if(strncmp(s,"weight",6) == 0) rtn = fWlWeight;
    else Fatal("GetTable(char*)","wrong type of table required");
    
    return rtn;
}

inline void EBunchPhotons::AddSingleRef( ESinglePhoton* ph ) {
    if(ph->GetType() == 0) {
        if(ph->GetHistory() == 0) fNumFluoDirect++;
        else if (ph->GetHistory() == 1) fNumFluoReflected++;
        else if (ph->GetHistory() == 2) fNumFluoAirScat++;
        else if (ph->GetHistory() == 3) fNumFluoCloudScat++;
        else if (ph->GetHistory() == 4) fNumFluoAeroScat++;
    }
    else if(ph->GetType() == 1) {
        if(ph->GetHistory() == 0) fNumCkovDirect++;
        else if (ph->GetHistory() == 1) fNumCkovReflected++;
        else if (ph->GetHistory() == 2) fNumCkovAirScat++;
        else if (ph->GetHistory() == 3) fNumCkovCloudScat++;
        else if (ph->GetHistory() == 4) fNumCkovAeroScat++;
    }
    else Warning("EBunchPhotons::AddSingleRef","Wrong photon type");
    
    fSingles->Add( ph );
}

inline void EBunchPhotons::SetShowerPosi( const TVector3& v ){
    fShowerPosiX = v.X();
    fShowerPosiY = v.Y();
    fShowerPosiZ = v.Z();
} 

inline void EBunchPhotons::SetShowerPosf( const TVector3& v ){
    fShowerPosfX = v.X();
    fShowerPosfY = v.Y();
    fShowerPosfZ = v.Z();
} 

inline void EBunchPhotons::SetFinalPos( const TVector3& v ){
    fFinalPosX = v.X();
    fFinalPosY = v.Y();
    fFinalPosZ = v.Z();
}

inline void EBunchPhotons::SetMeanDir( const TVector3& v ){
    fMeanDirX = v.X();
    fMeanDirY = v.Y();
    fMeanDirZ = v.Z();
}

inline Int_t EBunchPhotons::GetNumAll(TString type) const {
    Int_t rtn = 0;
    if(type == "fluo") rtn = fNumFluoDirect + fNumFluoReflected + fNumFluoAirScat + fNumFluoCloudScat + fNumFluoAeroScat;
    else if(type == "ckov") rtn = fNumCkovDirect + fNumCkovReflected + fNumCkovAirScat + fNumCkovCloudScat + fNumCkovAeroScat;
    else if(type == "all")
        rtn = fNumCkovDirect + fNumFluoDirect + fNumFluoReflected + fNumCkovReflected + fNumFluoAirScat + fNumCkovAirScat + fNumFluoCloudScat + fNumCkovCloudScat + fNumFluoAeroScat + fNumCkovAeroScat;
    else Warning("EBunchPhotons::GetNumAll","Wrong \'type\' argument");
    
    return rtn;
}

inline Int_t EBunchPhotons::GetNumDirect(TString type) const {
    Int_t rtn = 0;
    if(type == "fluo") rtn = fNumFluoDirect;
    else if(type == "ckov") rtn = fNumCkovDirect;
    else if(type == "all") rtn = fNumCkovDirect + fNumFluoDirect;
    else Warning("EBunchPhotons::GetNumDirect","Wrong \'type\' argument");
    
    return rtn;
}

inline Int_t EBunchPhotons::GetNumAirScat(TString type) const {
    Int_t rtn = 0;
    if(type == "fluo") rtn = fNumFluoAirScat;
    else if(type == "ckov") rtn = fNumCkovAirScat;
    else if(type == "all") rtn = fNumCkovAirScat + fNumFluoAirScat;
    else Warning("EBunchPhotons::GetNumAirScat","Wrong \'type\' argument");
    
    return rtn;
}

inline Int_t EBunchPhotons::GetNumAeroScat(TString type) const {
    Int_t rtn = 0;
    if(type == "fluo") rtn = fNumFluoAeroScat;
    else if(type == "ckov") rtn = fNumCkovAeroScat;
    else if(type == "all") rtn = fNumCkovAeroScat + fNumFluoAeroScat;
    else Warning("EBunchPhotons::GetNumAeroScat","Wrong \'type\' argument");
    
    return rtn;
}

inline Int_t EBunchPhotons::GetNumCloudScat(TString type) const {
    Int_t rtn = 0;
    if(type == "fluo") rtn = fNumFluoCloudScat;
    else if(type == "ckov") rtn = fNumCkovCloudScat;
    else if(type == "all") rtn = fNumCkovCloudScat + fNumFluoCloudScat;
    else Warning("EBunchPhotons::GetNumCloudScat","Wrong \'type\' argument");
    
    return rtn;
}

inline Int_t EBunchPhotons::GetNumReflected(TString type) const {
    Int_t rtn = 0;
    if(type == "fluo") rtn = fNumFluoReflected;
    else if(type == "ckov") rtn = fNumCkovReflected;
    else if(type == "all") rtn = fNumCkovReflected + fNumFluoReflected;
    else Warning("EBunchPhotons::GetNumReflected","Wrong \'type\' argument");
    
    return rtn;
}


#endif  /* __EBUNCHPHOTONS_HH_ */

