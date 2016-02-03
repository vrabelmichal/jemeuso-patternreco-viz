// $Id: ELblTrackSegment.hh 2167 2005-10-10 16:21:14Z ejudd $
// Author: E.Judd   2005/07/21

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ELblTrackSegment                                                     *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __ELBLTRACKSEGMENT_HH__
#define __ELBLTRACKSEGMENT_HH__

#include "TObject.h"
#include "EFillable.hh"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// ELblTrackSegment                                                          //
//                                                                            //  
// Holds info about a track found by the LBL chip-based trigger algorithm     //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class ELblTrackSegment : public TObject {
public:
    ELblTrackSegment();
    //ctor
    
    virtual ~ELblTrackSegment();
    //dtor
    
    ELblTrackSegment( const ELblTrackSegment& other );
    //copy ctor

    virtual void Copy( TObject& other ) const;
    //Copy method
    
    virtual void Clear( Option_t* = "" );
    //Clear method

    //getters
    inline Int_t GetCellId() const { return fCellId; }
    inline Int_t GetChipUid() const { return fChipUid; }
    inline Int_t GetGtuStart() const { return fGtuStart; }
    inline Int_t GetGtuEnd() const { return fGtuEnd; }
    inline Int_t GetRowStart() const { return fRowStart; }
    inline Int_t GetRowEnd() const { return fRowEnd; }
    inline Int_t GetColStart() const { return fColStart; }
    inline Int_t GetColEnd() const { return fColEnd; }
    inline Int_t GetNumSegs() const { return fNumSegs; }
    inline Int_t GetSum() const { return fSum; }
    inline Int_t GetTriggerID() const { return fTriggerID; }
    
    //setters
    inline void SetCellId(Int_t v)  { fCellId = v; }
    inline void SetChipUid(Int_t v) { fChipUid = v; }
    inline void SetGtuStart(Int_t v) { fGtuStart = v; }
    inline void SetGtuEnd(Int_t v) { fGtuEnd = v; }
    inline void SetRowStart(Int_t v) { fRowStart = v; }
    inline void SetRowEnd(Int_t v) { fRowEnd = v; }
    inline void SetColStart(Int_t v) { fColStart = v; }
    inline void SetColEnd(Int_t v) { fColEnd = v; }
    inline void SetNumSegs(Int_t v) { fNumSegs = v; }
    inline void SetSum(Int_t v) { fSum = v; }
    inline void SetTriggerID(Int_t v) { fTriggerID = v; }


private:
    Int_t fCellId;      // id of macrocell where track occured
    Int_t fChipUid;     // uid of chip where track occurred
    Int_t fGtuStart;    // first gtu
    Int_t fGtuEnd;      // last gtu
    Int_t fRowStart;    // first row
    Int_t fRowEnd;      // last row
    Int_t fColStart;    // first column
    Int_t fColEnd;      // last column
    Int_t fNumSegs;     // number of sections
    Int_t fSum;         // total ADC sum
    Int_t fTriggerID;   // ID number of this trigger in this EC

    SetEVisitable()
    ClassDef(ELblTrackSegment,1)
};

#endif  /* __ELBLTRACKSEGMENT_HH__ */

