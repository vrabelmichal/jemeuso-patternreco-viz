// $Id$
// Author: fenu2   2009/10/27

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EPTTTrigger                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __EPTTTRIGGER_HH__
#define __EPTTTRIGGER_HH__

#include "root/include/EFillable.hh"
#include "TObject.h"
#include "TClonesArray.h"
//#include <iostream.h>
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EPTTrigger                                                                 //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////
class EPTTTriggerSegment;
class EPTTTrigger:public TObject, public EFillable
{
public:
  EPTTTrigger ();
  virtual ~ EPTTTrigger ();
  EPTTTrigger (const EPTTTrigger &);
  Int_t fNumTrigg;
  TClonesArray *fPTTFlag;
  virtual void Copy (TObject &) const;

  //returns information about triggering macrocells 
  //as parameter number of triggering macrocell within the event
  inline EPTTTriggerSegment *GetPTTTrack (Int_t i)
  {
    return (EPTTTriggerSegment *) fPTTFlag->At (i);
  }

  //returns how may macrocells are triggering within one event
  inline Int_t GetPTTTrackNum ()
  {
    return fPTTFlag->GetEntries ();
  }

  virtual void Clear (Option_t * = "");
  void ClearCopy ();
private:
  Bool_t fCopy;
  static TClonesArray *fgPTTFlag;
  static EPTTTrigger *fgCurrent; 
  SetEVisitable ()
  ClassDef (EPTTTrigger, 1)

};

#endif /* __EPTTTRIGGER_HH__ */
