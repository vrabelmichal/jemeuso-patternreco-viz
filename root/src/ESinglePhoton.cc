// ESAF : Euso Simulation and Analysis Framework
// $Id: ESinglePhoton.cc 2765 2006-11-15 14:59:23Z moreggia $
// A.Thea created Jun,  9 2004

#include "ESinglePhoton.hh"

ClassImp(ESinglePhoton)

//_____________________________________________________________________________
ESinglePhoton::ESinglePhoton() : TObject() {
    // ctor
    Clear();
}

//_____________________________________________________________________________
ESinglePhoton::~ESinglePhoton() {
    // dtor
}

//_____________________________________________________________________________
void ESinglePhoton::Clear( Option_t* opt ){

    fType          = 0;
    fAbsorbed      = false;
    fCloudAbsorbed = false;
    fOutFoV        = false;
    fDate          = 0;
    fShowerAge     = -1;
    fBunchId       = 0;
    fHistory       = 0;
    fTof           = 0;
    fWl            = 0;
    fNbinter       = 0;
    fPosX          = -10000;
    fPosY          = -10000;
    fPosZ          = -10000;
    fShowerPosX    = 0;
    fShowerPosY    = 0;
    fShowerPosZ    = 0;
    fAllHistory.Reset();
    fLastTotTrans   = 0;
    fLastRaylTrans  = 0;
    fLastOzoneTrans = 0;
    fLastAeroTrans  = 0;
    fLastCloudTrans = 0;
}


