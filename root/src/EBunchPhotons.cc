// ESAF : Euso Simulation and Analysis Framework
// $Id: EBunchPhotons.cc 2863 2011-02-18 11:00:44Z biktem $
// A.Thea created Jun, 13 2004

#include "EBunchPhotons.hh"

ClassImp(EBunchPhotons)

//_____________________________________________________________________________
EBunchPhotons::EBunchPhotons() : TObject() {
    //
    // ctor
    //
    fWlLambda = 0;
    fWlWeight = 0;

    fSingles = new TRefArray;

    Clear();
}

//_____________________________________________________________________________
EBunchPhotons::~EBunchPhotons() {
    //
    // dtor
    //
    Clear();

    if(fSingles) delete fSingles;
    fSingles = 0;

}

//_____________________________________________________________________________
EBunchPhotons::EBunchPhotons(const EBunchPhotons& other) : TObject() {
    //
    // copy ctor
    //
    other.Copy( *this );
}

//_____________________________________________________________________________
void EBunchPhotons::Copy( TObject& other) const {
    //
    // copy
    //

    EBunchPhotons& o = (EBunchPhotons&)other;
    o.Clear();
    o.fType = fType;
    o.fId = fId;
    o.fDatei = fDatei;
    o.fDatef = fDatef;
    o.fShowerAge = fShowerAge;
    o.fShowerPosiX = fShowerPosiX;
    o.fShowerPosiY = fShowerPosiY;
    o.fShowerPosiZ = fShowerPosiZ;
    o.fShowerPosfX = fShowerPosfX;
    o.fShowerPosfY = fShowerPosfY;
    o.fShowerPosfZ = fShowerPosfZ;
    o.fFinalPosX = fFinalPosX;
    o.fFinalPosY = fFinalPosY;
    o.fFinalPosZ = fFinalPosZ;
    o.fMeanDirX = fMeanDirX;
    o.fMeanDirY = fMeanDirY;
    o.fMeanDirZ = fMeanDirZ;

    o.fWeight = fWeight;
    o.fYield = fYield;

    delete [] o.fWlLambda; o.fWlLambda = 0;
    delete [] o.fWlWeight; o.fWlWeight = 0;

    if ( fNumWavelengths > 0 ) {
        o.fNumWavelengths = fNumWavelengths;
        o.fWlLambda = new Float_t[fNumWavelengths];
        o.fWlWeight = new Float_t[fNumWavelengths];
        for ( Int_t i=0; i<fNumWavelengths; i++ ) {
            o.fWlLambda[i] = fWlLambda[i];      // [fNumWavelengths] array of wl values
            o.fWlWeight[i] = fWlWeight[i];      // [fNumWavelengths] array of wl weights values
        }
    }

    o.fNumFluoDirect = fNumFluoDirect;
    o.fNumCkovDirect = fNumCkovDirect;
    o.fNumFluoAirScat = fNumFluoAirScat;
    o.fNumCkovAirScat = fNumCkovAirScat;
    o.fNumFluoAeroScat = fNumFluoAeroScat;
    o.fNumCkovAeroScat = fNumCkovAeroScat;
    o.fNumFluoCloudScat = fNumFluoCloudScat;
    o.fNumCkovCloudScat = fNumCkovCloudScat;
    o.fNumFluoReflected = fNumFluoReflected;
    o.fNumCkovReflected = fNumCkovReflected;

    o.fFate = fFate;

}

//_____________________________________________________________________________
void EBunchPhotons::Clear( Option_t* opt) {
    //
    // clear
    //
    fType = 0;
    fId = 0;
    fWeight = 0;
    fDatei = 0;
    fDatef = 0;
    fShowerAge = -1;
    fShowerPosiX = -10000;
    fShowerPosiY = -10000;
    fShowerPosiZ = -10000;
    fShowerPosfX = -10000;
    fShowerPosfY = -10000;
    fShowerPosfZ = -10000;
    fFinalPosX = -10000;
    fFinalPosY = -10000;
    fFinalPosZ = -10000;
    fMeanDirX = -10000;
    fMeanDirY = -10000;
    fMeanDirZ = -10000;
    fYield = 0;
    fFate = 0;

    fNumWavelengths = 0;
    if(fWlLambda) delete[] fWlLambda;
    if(fWlWeight) delete[] fWlWeight;
    fWlLambda = 0;
    fWlWeight = 0;

    fNumFluoDirect = 0;
    fNumCkovDirect = 0;
    fNumFluoAirScat = 0;
    fNumCkovAirScat = 0;
    fNumFluoAeroScat = 0;
    fNumCkovAeroScat = 0;
    fNumFluoCloudScat = 0;
    fNumCkovCloudScat = 0;
    fNumFluoReflected = 0;
    fNumCkovReflected = 0;

    fSingles->Delete();
}

//______________________________________________________________________________
void EBunchPhotons::SetSpectrum ( Int_t n, const Float_t* lambda, const Float_t* integral){
    fNumWavelengths = n;

    if ( fWlLambda ) delete [] fWlLambda;
    fWlLambda = new Float_t[n];

    if ( fWlWeight ) delete [] fWlWeight;
    fWlWeight = new Float_t[n];

    for (Int_t i=0; i<n; i++) {
        fWlLambda[i] = lambda[i];
	fWlWeight[i] = (i == 0) ? integral[0] : integral[i] - integral[i-1];
    }
}
