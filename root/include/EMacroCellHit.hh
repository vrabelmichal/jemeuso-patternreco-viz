// ESAF : Euso Simulation and Analysis Framework
// $Id: EMacroCellHit.hh 824 2004-06-25 14:26:19Z thea $
//  created May, 23 2004

#ifndef __EMACROCELLHIT_HH_
#define __EMACROCELLHIT_HH_

#include "TObject.h"
#include "root/include/EFillable.hh"

// decription of a macrocell hit
class EMacroCellHit : public TObject {
public:
    EMacroCellHit();
    // ctor
    
    EMacroCellHit(const EMacroCellHit&);
    // copy ctor

    virtual ~EMacroCellHit();
    // dtor

    virtual void Copy( TObject& ) const;
    // copy to existing object

    virtual void Clear( Option_t* = "");
    // clear

    // getters
    inline Int_t GetCellId() { return fCellId; }
    inline Int_t GetChUId() { return fChUId; }
    inline Int_t GetGtu() { return fGtu; }
    inline Int_t GetCounts() { return fCounts; }
    inline Int_t GetCellRow() { return fCellRow; }
    inline Int_t GetCellCol() { return fCellCol; }
    inline Float_t GetTime() { return fTime; }
    
    // setters
    inline void SetCellId( Int_t val ) { fCellId = val; }
    inline void SetChUId( Int_t val ) { fChUId = val; }
    inline void SetGtu( Int_t val ) { fGtu = val; }
    inline void SetCounts( Int_t val ) { fCounts = val; }
    inline void SetCellRow( Int_t r ) { fCellRow = r; }
    inline void SetCellCol( Int_t c ) { fCellCol = c; }
    inline void SetTime( Float_t val ) { fTime = val; }
    
    ClassDef(EMacroCellHit,1)

private:
    Int_t fCellId;        // macro cell identifier 
    Int_t fChUId;         // channel unique identifier
    Int_t fGtu;           // gtu number for this event
    Int_t fCounts;        // number of detected photons by fast or
    Int_t fCellRow;       // local macrocell row number 
    Int_t fCellCol;       // local macrocell col number
    Float_t fTime;        // time in ns relative to first triggering gtu [ns]

    friend class EDetector;
    SetEVisitable()
};



#endif  /* __EMACROCELLHIT_HH_ */

