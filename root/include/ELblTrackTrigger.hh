// $Id: ELblTrackTrigger.hh 2167 2005-10-10 16:21:14Z ejudd $
// Author: E.Judd   2005/07/21

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ELblTrackTrigger                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __ELBLTRACKTRIGGER_HH__
#define __ELBLTRACKTRIGGER_HH__

#include "root/include/EFillable.hh"
#include "TObject.h"
#include "TClonesArray.h"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// ELblTrackTrigger                                                           //
//                                                                            //  
// Contains tracks found by the LBL chip-based trigger algorithm              //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class ELblTrackSegment;

class ELblTrackTrigger : public TObject, public EFillable {
public:
    ELblTrackTrigger();
    //ctor
    
    virtual ~ELblTrackTrigger();
    //dtor

    ELblTrackTrigger(const ELblTrackTrigger&);
    // copy ctor

    virtual void Copy( TObject& ) const;
    // copy this

    virtual void Clear( Option_t* ="" );
    // clear method

    inline static ELblTrackTrigger* GetCurrent() { return fgCurrent; }
    inline static void SetCurrent(ELblTrackTrigger *ev) { fgCurrent=ev; }

    // getters
    inline Int_t GetNumLblTracks() { return fNumLblTracks; }
    inline ELblTrackSegment* GetLblTrack( Int_t i ) { return (ELblTrackSegment*)fLblTracks->At(i); }

private:
    Int_t fNumLblTracks;       // total number of tracks
    TClonesArray* fLblTracks;  //->

    static TClonesArray *fgLblTracks;
    
    // the following is needed to handle events built with the copy constructor
    // in this case the TClonesArray are handled differently
    Bool_t fCopy;
    inline void SetCopy(Bool_t val = kTRUE ) { fCopy = val; }
    inline Bool_t IsCopy() const { return fCopy;}
    void ClearCopy();

    static ELblTrackTrigger* fgCurrent;

    SetEVisitable()
    ClassDef(ELblTrackTrigger,1)
};

#endif  /* __ELBLTRACKTRIGGER_HH__ */

