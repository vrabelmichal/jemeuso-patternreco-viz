// ESAF : Euso Simulation and Analysis Framework
// $Id: EElectronics.cc 831 2004-06-25 17:06:02Z thea $
// A.Thea created Jun, 23 2004

#include "root/include/EElectronics.hh"
#include "root/include/Etypes.hh"

ClassImp(EElectronics)

//_____________________________________________________________________________
EElectronics::EElectronics() {
    // ctor

    Clear();
}

//_____________________________________________________________________________
EElectronics::EElectronics(const EElectronics& other ) : TObject() {
    // copy ctor
    
    other.Copy( *this );
}
//_____________________________________________________________________________
EElectronics::~EElectronics() {
    // dtor
}

//_____________________________________________________________________________
void EElectronics::Copy( TObject& other) const {
    // copy
    
    TObject::Copy( other );

    ((EElectronics&)other).fNumActiveGtus = fNumActiveGtus;
    ((EElectronics&)other).fGtuStart      = fGtuStart;
    ((EElectronics&)other).fGtuEnd        = fGtuEnd;
    ((EElectronics&)other).fNumCells      = fNumCells;
    ((EElectronics&)other).fTimeGtu0      = fTimeGtu0;
    ((EElectronics&)other).fTimeFirstGtu  = fTimeFirstGtu;
    ((EElectronics&)other).fTimeLastGtu   = fTimeLastGtu;
    ((EElectronics&)other).fGtuLength     = fGtuLength;
    
}

//_____________________________________________________________________________
void EElectronics::Clear( Option_t* option ) {
    // clear object
    
    fNumActiveGtus = -1;
    fGtuStart      = -1;
    fGtuEnd        = -1;
    fNumCells      = -1;
    fTimeGtu0      =  kHuge;
    fTimeFirstGtu  =  kHuge;
    fTimeLastGtu   = -kHuge;
    fGtuLength     = -1;

}
