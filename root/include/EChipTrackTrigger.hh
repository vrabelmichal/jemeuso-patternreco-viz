// $Id: EChipTrackTrigger.hh 1490 2005-02-15 15:07:20Z pesce $
// Author: R.Pesce   2005/02/15

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EChipTrackTrigger                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __ECHIPTRACKTRIGGER_HH__
#define __ECHIPTRACKTRIGGER_HH__

#include "root/include/EFillable.hh"
#include "TObject.h"
#include "TClonesArray.h"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EChipTrackTrigger                                                                 //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class EChipTrackSegment;

class EChipTrackTrigger : public TObject, public EFillable {
public:
    EChipTrackTrigger();
    //ctor
    
    virtual ~EChipTrackTrigger();
    //dtor

    EChipTrackTrigger(const EChipTrackTrigger&);
    // copy ctor

    virtual void Copy( TObject& ) const;
    // copy this

    virtual void Clear( Option_t* ="" );
    // clear method

    inline static EChipTrackTrigger* GetCurrent() { return fgCurrent; }
    inline static void SetCurrent(EChipTrackTrigger *ev) { fgCurrent=ev; }

    // getters
    inline Int_t GetNumTracks() { return fNumTracks; }
    inline EChipTrackSegment* GetTrack( Int_t i ) { return (EChipTrackSegment*)fTracks->At(i); }

private:
    Int_t fNumTracks;       // total number of tracks
    TClonesArray* fTracks;  //->

    static TClonesArray *fgTracks;
    
    // the following is needed to handle events built with the copy constructor
    // in this case the TClonesArray are handled differently
    Bool_t fCopy;
    inline void SetCopy(Bool_t val = kTRUE ) { fCopy = val; }
    inline Bool_t IsCopy() const { return fCopy;}
    void ClearCopy();

    static EChipTrackTrigger* fgCurrent;

    SetEVisitable()
    ClassDef(EChipTrackTrigger,1)
};

#endif  /* __ECHIPTRACKTRIGGER_HH__ */

