// ESAF : Euso Simulation and Analysis Framework
// $Id: EElectronics.hh 831 2004-06-25 17:06:02Z thea $
// A.Thea created Jun, 23 2004

#ifndef __EELECTRONICS_HH_
#define __EELECTRONICS_HH_

#include "TObject.h"
#include "EFillable.hh"

// data from Euso electronics
class EElectronics : public TObject {
public:
    EElectronics();
    // ctor

    EElectronics(const EElectronics&);
    // copy ctor

    virtual ~EElectronics();
    // dtor
    
    virtual void Clear( Option_t* = "");
    // clear object

    virtual void Copy( TObject& ) const;

    // getters
    inline Int_t GetNumActiveGtus() const { return fNumActiveGtus;}
    inline Int_t GetGtuStart() const { return fGtuStart;}
    inline Int_t GetGtuEnd() const { return fGtuEnd;}
    inline Int_t GetNumCells() const { return fNumCells;}
    inline Float_t GetTimeGtu0() const { return fTimeGtu0;}
    inline Float_t GetTimeFirstGtu() const { return fTimeFirstGtu;}
    inline Float_t GetTimeLastGtu() const { return fTimeLastGtu;}
    inline Float_t GetGtuLength() const { return fGtuLength;}

    // setters
    inline void SetNumActiveGtus(Int_t val) { fNumActiveGtus = val;}
    inline void SetGtuStart(Int_t val) { fGtuStart = val;}
    inline void SetGtuEnd(Int_t val) { fGtuEnd = val;}
    inline void SetNumCells(Int_t val) { fNumCells = val;} 
    inline void SetTimeGtu0(Float_t val) {fTimeGtu0 = val;}
    inline void SetTimeFirstGtu(Float_t val) {fTimeFirstGtu = val;}
    inline void SetTimeLastGtu(Float_t val) {fTimeLastGtu = val;} 
    inline void SetGtuLength(Float_t val) {fGtuLength = val;}

private:
    Int_t fNumActiveGtus;   // total number of GTUs in which there was activity
    Int_t fGtuStart;        // first GTU with data
    Int_t fGtuEnd;          // last GTU in data
    Int_t fNumCells;        // number of macrocells with data
    Float_t fTimeGtu0;      // time (ns) corresponding to first edge of gtu 0
    Float_t fTimeFirstGtu;  // time (ns) corresponding to first edge first active gtu
    Float_t fTimeLastGtu;   // time (ns) corresponding to second edge last active gtu
    Float_t fGtuLength;     // time duration (ns) of one GTU
    
    SetEVisitable()

    ClassDef(EElectronics,1)
};

#endif  /* __EELECTRONICS_HH_ */

