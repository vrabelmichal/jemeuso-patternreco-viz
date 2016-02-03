// $Id$
// Author: fenu2   2009/10/27

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ECCB_LTTTrigger                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __ECCB_LTTTRIGGER_HH__
#define __ECCB_LTTTRIGGER_HH__

#include "EFillable.hh"
#include "TObject.h"
#include "TClonesArray.h"
//#include <iostream.h>
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// ECCB_LTTTrigger                                                                 //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////
class ECCB_LTTTriggerSegment;
class ECCB_LTTTrigger : public TObject, public EFillable {
public:
    ECCB_LTTTrigger();
    virtual ~ECCB_LTTTrigger();
   ECCB_LTTTrigger(const ECCB_LTTTrigger&);
  Int_t fNumTrigg; 
 TClonesArray *fCCB_LTTFlag;
    virtual void Copy( TObject& ) const;

  //returns information about triggering macrocells 
  //as parameter number of triggering macrocell within the event
  inline ECCB_LTTTriggerSegment* GetCCB_LTTTrack( Int_t i ) {  return (ECCB_LTTTriggerSegment*)fCCB_LTTFlag->At(i); }

  //returns how may macrocells are triggering within one event
  inline Int_t GetCCB_LTTTrackNum() {return fCCB_LTTFlag->GetEntries();}

    virtual void Clear( Option_t* ="" );
void ClearCopy();
private: 
   Bool_t fCopy;
    static TClonesArray *fgCCB_LTTFlag;
    static ECCB_LTTTrigger* fgCurrent;
    SetEVisitable()
    ClassDef(ECCB_LTTTrigger,1)

//friend class ThirdLevelTrigger;

};

#endif  /* __ECCB_LTTTRIGGER_HH__ */

