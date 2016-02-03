// $Id: EAFee.cc 1896 2005-05-30 08:31:12Z thea $
// Author: M.Pallavicini, A.Thea

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EAFee                                                                 *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/

#include "EAFee.hh"

ClassImp(EAFee)

//______________________________________________________________________________
//
//  EAFee
//  =====
//
//  Analog Front End electronics infos For each GTU, last dynode charge and
//  trigger infos are written (if any) Full AFEE is stored in EFee object
//  (because is channel based and not GTU based )
//

//_____________________________________________________________________________
EAFee::EAFee() {
    // ctor

    fGtu       = -1;
    fMCId      = -1;
    fFEId      = -1;
    fDyCharge  = 0;
    fCherTrigg = 0;
}

//_____________________________________________________________________________
EAFee::EAFee(const EAFee& other) : TObject() {
    // copy ctor
    
   
    ((EAFee&)other).Copy(*this); 
    
}
//_____________________________________________________________________________
EAFee::~EAFee() {
    // dtor
}

//_____________________________________________________________________________
void EAFee::Copy( TObject& obj) const {
    // copy this afee to obj 
    
    TObject::Copy(obj);

    EAFee& afee = (EAFee&)obj;
    afee.fGtu       = fGtu;
    afee.fMCId      = fMCId;
    afee.fFEId      = fFEId;
    afee.fDyCharge  = fDyCharge;
    afee.fCherTrigg = fCherTrigg;
}

