// ESAF : Euso Simulation and Analysis Framework
// $Id: EAtmosphere.hh 2605 2006-03-20 23:41:19Z thea $
// Alessandro Thea created May, 28 2004

#ifndef __EATMOSPHERE_HH_
#define __EATMOSPHERE_HH_

#include "TObject.h"
#include "TClonesArray.h"

#include "root/include/EFillable.hh"

class EBunchPhotons;
class ESinglePhoton;

class EAtmosphere : public TObject, public EFillable {
public:
    EAtmosphere();
    // ctor

    EAtmosphere(const EAtmosphere&);
    // copy ctor

    virtual ~EAtmosphere();
    // dtor

    virtual void Copy( TObject& ) const;
    // copy this

    virtual void Clear( Option_t* ="" );
    virtual void ClearAndShrink( Option_t* ="" );

    inline static EAtmosphere* GetCurrent() { return fgCurrent; }
    inline static void SetCurrent(EAtmosphere *ev) { fgCurrent=ev; }

    // getters
    inline Int_t GetNumBunches() {return fNumBunches; }
    inline Int_t GetNumSingles() { return fNumSingles; }
    inline Int_t GetMaxScatOrder() {return fMaxScatOrder;}
    inline EBunchPhotons* GetBunch( Int_t i ) { return (EBunchPhotons*)fBunches->At(i); }
    inline ESinglePhoton* GetSingle( Int_t i ) { return (ESinglePhoton*)fSingles->At(i); }
    inline void SetMaxScatOrder(Int_t i) {fMaxScatOrder = i;}

    void AddTestPhoton();
    void AddTestBunch(Int_t);

private:

    Int_t fNumBunches;       // number of bunch photons
    Int_t fNumSingles;       // number of single photons
    Int_t fMaxScatOrder;     // (for MCRadiativeTransfer only) Maximum scattering order simulated
    TClonesArray *fBunches;  //->
    TClonesArray *fSingles;  //->

//    static TClonesArray *fgBunches;
//    static TClonesArray *fgSingles;

    // the following is needed to handle events built with the copy constructor
    // in this case the TClonesArray are handled differently
    Bool_t fCopy;
    inline void SetCopy(Bool_t val = kTRUE ) { fCopy = val; }
    inline Bool_t IsCopy() const { return fCopy;}
   
    static EAtmosphere* fgCurrent;

    SetEVisitable()    

    ClassDef(EAtmosphere,1)
};

#endif  /* __EATMOSPHERE_HH_ */

