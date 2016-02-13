// $Id$
// Author: fenu2   2009/10/27

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ELTTTrigger                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __ELTTTRIGGER_HH__
#define __ELTTTRIGGER_HH__

#include "root/include/EFillable.hh"
#include "TObject.h"
#include "TClonesArray.h"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// ELTTTrigger                                                                 //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////
class ELTTTriggerSegment;
class ELTTTrigger : public TObject, public EFillable {
public:
    ELTTTrigger();
    virtual ~ELTTTrigger();
   ELTTTrigger(const ELTTTrigger&);
  Int_t fNumTrigg; 
 TClonesArray *fLTTFlag;
    virtual void Copy( TObject& ) const;

  //returns information about triggering macrocells 
  //as parameter number of triggering macrocell within the event
  inline ELTTTriggerSegment* GetLTTTrack( Int_t i ) {  return (ELTTTriggerSegment*)fLTTFlag->At(i); }

  //returns how may macrocells are triggering within one event
  inline Int_t GetLTTTrackNum() {return fLTTFlag->GetEntries();}

    virtual void Clear( Option_t* ="" );
void ClearCopy();
private: 
   Bool_t fCopy;
    static TClonesArray *fgLTTFlag;
    static ELTTTrigger* fgCurrent;
    SetEVisitable()
    ClassDef(ELTTTrigger,1)
};

#endif  /* __ELTTTRIGGER_HH__ */

