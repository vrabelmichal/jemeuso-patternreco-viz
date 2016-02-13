// ESAF : Euso Simulation and Analysis Framework
// $Id: EMacroCellHit.cc 718 2004-06-11 15:12:41Z thea $
//  created May, 23 2004

#include "root/include/EMacroCellHit.hh"

ClassImp(EMacroCellHit)

//_____________________________________________________________________________
EMacroCellHit::EMacroCellHit() {
    // ctor

    Clear();
}

//_____________________________________________________________________________
EMacroCellHit::EMacroCellHit(const EMacroCellHit& other) : TObject() {
    // copy ctor
    
    other.Copy( *this );
}

//_____________________________________________________________________________
EMacroCellHit::~EMacroCellHit() {
    // dtor
}

//_____________________________________________________________________________
void EMacroCellHit::Copy( TObject& other) const {
    // copy
    
    TObject::Copy( other );

    ((EMacroCellHit&)other).fCellId = fCellId;
    ((EMacroCellHit&)other).fChUId  = fChUId;
    ((EMacroCellHit&)other).fGtu    = fGtu;
    ((EMacroCellHit&)other).fCounts = fCounts;
    ((EMacroCellHit&)other).fTime   = fTime;
}


//_____________________________________________________________________________
void EMacroCellHit::Clear( Option_t* opt ) {
    // clear this hit
    
    fCellId                 = 0;
    fChUId                  = 0;
    fGtu                    = -1;
    fCounts                 = -1;
    fTime                   = -1e20;
}
