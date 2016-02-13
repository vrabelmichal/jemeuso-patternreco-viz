// ESAF : Euso Simulation and Analysis Framework
// $Id: EAtmosphere.cc 2877 2011-04-25 14:15:15Z biktem $
// Alessandro Thea created May, 28 2004

#include "root/include/EAtmosphere.hh"
#include "root/include/ESinglePhoton.hh"
#include "root/include/EBunchPhotons.hh"

ClassImp(EAtmosphere)

//TClonesArray* EAtmosphere::fgBunches = NULL;
//TClonesArray* EAtmosphere::fgSingles = NULL;
EAtmosphere* EAtmosphere::fgCurrent = NULL;

const Int_t fgDefClonesSize=10000;

//_____________________________________________________________________________
EAtmosphere::EAtmosphere() : TObject() {
    // ctor

//    if ( fgBunches == 0 )
//        fgBunches = new TClonesArray("EBunchPhotons",20000);
//
//    if ( fgSingles == 0 )
//        fgSingles = new TClonesArray("ESinglePhoton",20000);

    if (TClass::IsCallingNew()) {
        fBunches = 0;
        fSingles = 0;
    } else {
        fBunches = new TClonesArray("EBunchPhotons",fgDefClonesSize);
        fSingles = new TClonesArray("ESinglePhoton",fgDefClonesSize);
    }


    fCopy       = kFALSE;
    fNumBunches = 0;
    fNumSingles = 0;
    fMaxScatOrder =1;
}

//_____________________________________________________________________________
EAtmosphere::EAtmosphere(const EAtmosphere& other) : fBunches(0), fSingles(0) {
    // copy ctor
    other.Copy( *this );
}

//_____________________________________________________________________________
EAtmosphere::~EAtmosphere() {
    //
    // dtor
    //

    Clear();

    SafeDelete(fBunches);
    SafeDelete(fSingles);

    if ( GetCurrent() == this ) SetCurrent( 0 );
}

//_____________________________________________________________________________
void EAtmosphere::Copy( TObject& other) const {
    // copy

    EAtmosphere& atm = ( EAtmosphere&) other;

    // copy atmosphere variables
    atm.fNumBunches = fNumBunches;
    atm.fNumSingles = fNumSingles;
    atm.fMaxScatOrder = fMaxScatOrder;

    SafeDelete(atm.fBunches);
    SafeDelete(atm.fSingles);
    // create TClonesArray
    atm.fBunches = (TClonesArray*)fBunches->Clone();
    atm.fSingles = (TClonesArray*)fSingles->Clone();
}

//_____________________________________________________________________________
void EAtmosphere::Clear( Option_t* opt ) {
    // clear this obj
    if ( fBunches ) fBunches->Clear( opt );
    if ( fSingles ) fSingles->Clear( opt );
    fNumBunches = 0;
    fNumSingles = 0;
}

//______________________________________________________________________________
void EAtmosphere::ClearAndShrink( Option_t* opt) {
    //
    //
    //

    Clear( opt );
    if ( fBunches ) fBunches->Expand( fgDefClonesSize );
    if ( fSingles ) fSingles->Expand( fgDefClonesSize );
}

//______________________________________________________________________________
void EAtmosphere::AddTestPhoton() {

    ESinglePhoton* ph = new ((*fSingles)[fNumSingles++]) ESinglePhoton;
    if ( fBunches->At(fNumBunches-1) ) {
        EBunchPhotons* bunch = (EBunchPhotons*)fBunches->At(fNumBunches-1);
        bunch->AddSingleRef(ph);
    }

}

//______________________________________________________________________________
void EAtmosphere::AddTestBunch( Int_t nph) {

    new ((*fBunches)[fNumBunches++]) EBunchPhotons;
    for(Int_t i(0); i<nph; i++){
       AddTestPhoton();
    }

}
