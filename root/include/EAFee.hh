// $Id: EAFee.hh 1913 2005-06-03 12:39:50Z thea $
// Author: M.Pallavicini, A.Thea

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EAFee                                                                 *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/

#ifndef __EAFEE_HH__
#define __EAFEE_HH__

#include "TObject.h"
#include "EFillable.hh"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// EAFee                                                                     //
//                                                                           //
// Analog Front End electronics infos For each GTU, last dynode charge and   //
// trigger infos are written (if any) Full AFEE is stored in EFee object     //
// (because is channel based and not GTU based )                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class EAFee : public TObject {
public:
    EAFee();
    EAFee(const EAFee&);
    
    virtual ~EAFee();
    
    virtual void Copy( TObject &obj ) const;
    // copy this afee to a new one
    
    // getters 
    inline Int_t   GetGtu() const {return fGtu;}
    inline Int_t   GetMCId() const {return fMCId;}
    inline Int_t   GetFEId() const {return fFEId;}
    inline Float_t GetDyCharge() const {return fDyCharge;}
    inline Bool_t  GetCherTrigg() const {return fCherTrigg;}

    inline void SetGtu( Int_t gtu ) { fGtu = gtu ;}
    inline void SetMCId( Int_t mc ) { fMCId = mc; }
    inline void SetFEId( Int_t fe ) { fFEId= fe; }
    inline void SetDyCharge( Float_t c ) { fDyCharge = c;}
    inline void SetCherTrigg( Bool_t trig ) { fCherTrigg = trig;}
    
    ClassDef(EAFee,1)
        
private:
    Int_t fGtu;               // gtu identifier
    Int_t fMCId;              // macrocell identifier
    Int_t fFEId;              // front end identifier
    Float_t fDyCharge;        // dynode channel charge [coulomb]
    Bool_t fCherTrigg;        // true if Cerenkov trigger fired (if any, to be done!)

    SetEVisitable()
};

#endif  /* __EAFEE_HH__ */

