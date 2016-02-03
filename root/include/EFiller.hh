// ESAF : Euso Simulation and Analysis Framework
// $Id: EFiller.hh 824 2004-06-25 14:26:19Z thea $
// A.Thea created Jun, 11 2004

#ifndef __EFILLER_HH_
#define __EFILLER_HH_

#include "Rtypes.h"
#include "TString.h"

class EFillable;

class EFiller {
protected:
    // new ctor
    EFiller( const char* );

public:
    // dtor
    virtual ~EFiller();

    // abstract interface to any fill operation of root file
    virtual void Fill( EFillable* ) = 0;

    const char* GetTarget() const { return fTarget.Data(); }

    ClassDef(EFiller,1)

private:
    UInt_t fPermissions;
    TString fTarget;        // name of the class to fill

};

#endif  /* __EFILLER_HH_ */

