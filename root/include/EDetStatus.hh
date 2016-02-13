// $Id: EDetStatus.hh 2262 2005-10-24 10:42:29Z pesce $
// Author: Roberto Pesce   2005/09/27

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EDetStatus                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __EDETSTATUS_HH__
#define __EDETSTATUS_HH__

#include "TObject.h"
#include "TArrayI.h"
#include "root/include/Etypes.hh"
#include "root/include/EFillable.hh"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EDetStatus                                                                 //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class EDetStatus : public TObject {
public:
    EDetStatus();
    // ctor

    EDetStatus(const EDetStatus&);
    // copy ctor
    
    virtual ~EDetStatus();
    // dtor

    virtual void Clear( Option_t* = "" );
    // clear method

    virtual void Copy( TObject& ) const;
    // copy method


    // getters
    inline Int_t GetNumActivePixels() const { return fNumActivePixels; }
    inline Int_t GetNumSignals() const { return fNumSignals; }
    inline Int_t GetNumBkg() const { return fNumBkg; }
    inline Int_t GetNumHits() const { return fNumHits; }
    inline Int_t GetNumGtu() const { return fNumGtu;}
    inline Int_t GetNumPhotons() const { return fNumPhotons; }
    Int_t GetMaxHits( Int_t ) const;
    Int_t GetMaxBkg( Int_t ) const;
    Int_t GetMaxSignals( Int_t ) const;
    inline Int_t GetPhotonHistory( EDetectorSystem s ) const { return fPhotonHistory.At(s); }

    // setters
    inline void SetNumActivePixels( Int_t val ) { fNumActivePixels = val; }
    inline void SetNumSignals( Int_t val ) { fNumSignals = val; }
    inline void SetNumBkg( Int_t val ) { fNumBkg = val; }
    inline void SetNumHits( Int_t val ) { fNumHits = val; }
    inline void SetNumGtu( Int_t val ) { fNumGtu = val; }
    inline void SetNumPhotons( Int_t val ) { fNumPhotons=val; }
    inline void SetMaxHits( Int_t size, const Int_t *arr ) { fMaxHits.Set(size,arr); }
    inline void SetMaxSignals( Int_t size, const Int_t *arr ) { fMaxSignals.Set(size,arr); }
    inline void SetMaxBkg( Int_t size, const Int_t *arr ) { fMaxBkg.Set(size,arr); }

private:
    Int_t fNumActivePixels;   // pixels hitted by signal (active pixels)
    Int_t fNumSignals;        // total num of signal hits
    Int_t fNumBkg;            // total num of background hits (in active pixels)
    Int_t fNumHits;           // total num of total hits (in active pixels)
    Int_t fNumGtu;            // total num of gtus (with at least a signal)
    Int_t fNumPhotons;        // total num of photons

    TArrayI fPhotonHistory;   // summary of photon history
    TArrayI fMaxHits;         // array of max total hits in a pixel (for each gtu)
    TArrayI fMaxBkg;          // array of max background hits in a pixel (for each gtu)
    TArrayI fMaxSignals;      // array of max signal hits in a pixel (for each gtu)

    SetEVisitable()

    ClassDef(EDetStatus,1)
};

#endif  /* __EDETSTATUS_HH__ */

