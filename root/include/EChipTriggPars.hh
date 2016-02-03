// $Id: EChipTriggPars.hh 2264 2005-10-24 14:30:39Z pesce $
// Author: Roberto Pesce   2005/09/28

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EChipTriggPars                                                       *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __ECHIPTRIGGPARS_HH__
#define __ECHIPTRIGGPARS_HH__

#include "ETriggPars.hh"
#include "TString.h"
#include "TRef.h"
#include "Etypes.hh"
#include "EFillable.hh"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EChipTriggPars                                                             //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class EChipTriggPars : public ETriggPars {
public:
    EChipTriggPars();
    // ctor
    
    EChipTriggPars(const EChipTriggPars&);
    // copy ctor
    
    virtual ~EChipTriggPars();
    // dtor

    virtual void Copy(TObject&) const;
    // copy

    virtual void Clear( Option_t* ="" );
    // clear

    // getters
    //inline TString GetName() const { return fName; }
    
    inline Int_t GetThresholdNumber() const { return fThreshold; }
    // return only the number in fThreshold; if the threshold is absolute is the true
    // threshold used by the trigger engine

    Int_t GetThreshold( Int_t );
    // return the true threshold used by the trigger engine for a given microcell
    // it compute the threshold using mean background value in Run Parameters

    inline Bool_t HasRelativeThreshold() const { return fHasRelativeThreshold; }
    inline Int_t GetMinTrackLength() const { return fMinTrackLength; }
    inline Int_t GetMaxTrackLength() const { return fMaxTrackLength; }
    inline Int_t GetMinTriggerTrackLength() const { return fMinTriggerTrackLength; }
    inline Int_t GetMinTriggerTwoLength() const { return fMinTriggerTwoLength; }
    inline Int_t GetMaxTwoLength() const { return fMaxTwoLength; }
    inline Bool_t OnlyWithSignal() const { return fOnlyWithSignal; }
    inline Bool_t AcceptHole() const { return fAcceptHole; }
        
    // setters
    inline void SetThreshold( Int_t t ) { fThreshold=t; }
    inline void SetHasRelativeThreshold( Bool_t r ) { fHasRelativeThreshold=r; }
    inline void SetMinTrackLength( Int_t l ) { fMinTrackLength=l; }
    inline void SetMaxTrackLength( Int_t l ) { fMaxTrackLength=l; }
    inline void SetMinTriggerTrackLength( Int_t l ) { fMinTriggerTrackLength=l; }
    inline void SetMinTriggerTwoLength( Int_t l ) { fMinTriggerTwoLength=l; }
    inline void SetMaxTwoLength( Int_t l ) { fMaxTwoLength=l; }
    inline void SetOnlyWithSignal( Bool_t v ) { fOnlyWithSignal=v; }
    inline void SetAcceptHole( Bool_t v ) { fAcceptHole=v; }
        
private:
    Int_t fThreshold;
    Bool_t fHasRelativeThreshold;

    Int_t fMinTrackLength;
    Int_t fMaxTrackLength;

    Int_t fMinTriggerTrackLength;
    Int_t fMinTriggerTwoLength;

    Int_t fMaxTwoLength;

    Bool_t fOnlyWithSignal;
    Bool_t fAcceptHole;

    TRef fRunParsRef; // reference to the run parameters

    ClassDef(EChipTriggPars,1)

};

#endif  /* __ECHIPTRIGGPARS_HH__ */

