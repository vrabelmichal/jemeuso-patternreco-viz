// ESAF : Euso Simulation and Analysis Framework
// $Id: EShowerStep.cc 860 2004-06-30 20:06:27Z thea $
// A.Thea created Jun,  9 2004

#include "root/include/EShowerStep.hh"
#include "root/include/Etypes.hh"

ClassImp(EShowerStep)

//_____________________________________________________________________________
EShowerStep::EShowerStep() {
    // ctor

    fEnergyAngle       = 0;
    fRadPhiElectrons   = 0;
    fRadDTimeElectrons = 0;

    fRadPhiEnergyLoss  = 0;
    fAngleCherenkov    = 0;

    Clear();
}

//_____________________________________________________________________________
EShowerStep::~EShowerStep() {
    // dtor

    if ( fEnergyAngle )       delete fEnergyAngle;
    if ( fRadPhiElectrons )   delete fRadPhiElectrons;
    if ( fRadDTimeElectrons ) delete fRadDTimeElectrons;

    if ( fRadPhiEnergyLoss )  delete fRadPhiEnergyLoss;
    if ( fAngleCherenkov )    delete fAngleCherenkov;
}

//_____________________________________________________________________________
void EShowerStep::Clear( Option_t *opt ) {
    // clear this object
    
    fXi                 = 0;
    fXf                 = 0;
    fPosiX              = -kHuge;
    fPosiY              = -kHuge;
    fPosiZ              = -kHuge;
    fPosfX              = -kHuge;
    fPosfY              = -kHuge;
    fPosfZ              = -kHuge;
    fTimei              =  kHuge; 
    fTimef              = -kHuge;
    fAgei               = 0;
    fAgef               = 0;
    fNumElectrons       = 0;


    fNumCharged         = 0;
    fEnergyLoss         = 0;
    fNumCherenkov       = 0;

    if ( fEnergyAngle ) fEnergyAngle->Reset();
    if ( fRadPhiElectrons ) fRadPhiElectrons->Clear();
    if ( fRadDTimeElectrons ) fRadDTimeElectrons->Clear();

    if ( fRadPhiEnergyLoss ) fRadPhiEnergyLoss->Clear();
    if ( fAngleCherenkov ) fAngleCherenkov->Clear();

}
