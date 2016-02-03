// $Id: EFee.hh 1913 2005-06-03 12:39:50Z thea $
// Author: M.Pallavicini May, 23 2004

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EFee                                                                 *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/

#ifndef __EFEE_HH__
#define __EFEE_HH__

#include "TObject.h"
#include "EFillable.hh"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EFee                                                                       //
//                                                                            //
// Digital Front End electronics infos                                        //
// For each GTU, the number of detected photons per each channel is written   //
// Data is available for both DFEE and full AFEE                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

class EFee : public TObject {
public:
    EFee();
    // ctor
    
    EFee(const EFee&);
    // copy ctor
    
    virtual ~EFee();
    // dtor
    
    virtual void Copy( TObject& ) const ;
    // copy to new object

    // getters
    inline Int_t   GetGtu() {return fGtu;}                      // gtu identifier
    inline Int_t   GetFEId() {return fFEId;}                    // front end identifier
    inline Int_t   GetChUId() {return fChUId;}                  // unique channel number 
    inline Int_t   GetNumSignals() {return fNumSignals;}        // number of signal hits
    inline Int_t   GetNumHits() {return fNumHits;}              // number of detected hits 
    inline Bool_t  HasTriggered() {return fHasTriggered;}    
    inline Float_t GetChCharge() {return fChCharge;}           // channel charge

    inline void SetGtu( Int_t gtu ) { fGtu = gtu; }         // gtu identifier
    inline void SetFEId( Int_t id ) { fFEId = id;}          // front end identifier
    inline void SetChUId( Int_t id ) { fChUId = id;}        // unique channel number 
    inline void SetNumSignals( Int_t n ) {fNumSignals = n;} // number of signal hits
    inline void SetNumHits( Int_t n ) { fNumHits = n;}      // number of detected hits 
    inline void SetHasTriggered( Bool_t trgrd ) { fHasTriggered = trgrd; }
    inline void SetChCharge( Float_t c ) { fChCharge = c ;} // channel charge

    ClassDef(EFee,1)
        
private:
    Int_t fGtu;               // gtu identifier
    Int_t fFEId;              // front end identifier
    Int_t fChUId;             // channel unique identifier number 
    Int_t fNumHits;           // number of detected hits
    Int_t fNumSignals;        // number of pure signal hits
    Bool_t fHasTriggered;     // true if it was above digital counter threshold
    Float_t fChCharge;        // channel charge

    friend class EEvent;
    SetEVisitable()
};

#endif  /* __EFEE_HH_ */

