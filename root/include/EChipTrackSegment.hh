// $Id: EChipTrackSegment.hh 1488 2005-02-15 13:51:18Z pesce $
// Author: R.Pesce   2005/02/15

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EChipTrackSegment                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __ECHIPTRACKSEGMENT_HH__
#define __ECHIPTRACKSEGMENT_HH__

#include "TObject.h"
#include "EFillable.hh"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EChipTrackSegment                                                                 //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class EChipTrackSegment : public TObject {
public:
    EChipTrackSegment();
    //ctor
    
    virtual ~EChipTrackSegment();
    //dtor
    
    EChipTrackSegment( const EChipTrackSegment& other );
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
    inline Int_t GetCrossBorder() const { return fCrossBorder; }
    inline Int_t GetTrackLength() const { return fTrackLength; }
    inline Bool_t GetHasHole() const { return fHasHole; }
    inline Bool_t GetTriggered() const { return fTriggered; }
    
    //setters
    inline void SetCellId(Int_t v)  { fCellId = v; }
    inline void SetChipUid(Int_t v) { fChipUid = v; }
    inline void SetGtuStart(Int_t v) { fGtuStart = v; }
    inline void SetGtuEnd(Int_t v) { fGtuEnd = v; }
    inline void SetCrossBorder(Int_t v) { fCrossBorder = v; }
    inline void SetTrackLength(Int_t v) { fTrackLength = v; }
    inline void SetHasHole(Bool_t v) { fHasHole = v; }
    inline void SetTriggered(Bool_t v) { fTriggered = v; }


private:
    Int_t fCellId;      // id of macrocell where track occured
    Int_t fChipUid;     // uid of chip where track occurred
    Int_t fGtuStart;    // first gtu
    Int_t fGtuEnd;      // last gtu
    Int_t fCrossBorder; // true if track is touching the chip border
    Int_t fTrackLength; // length in number of pixels and gtu
    Bool_t fHasHole;    // true if the track has a hole
    Bool_t fTriggered;  // true if the track is a segment of a trigger track

    SetEVisitable()
    ClassDef(EChipTrackSegment,1)
};

#endif  /* __ECHIPTRACKSEGMENT_HH__ */

