// $Id$
// Author: fenu2   2009/10/29

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ELTTTriggerSegment                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __ELTTTRIGGERSEGMENT_HH__
#define __ELTTTRIGGERSEGMENT_HH__

#include "TObject.h"
#include "EFillable.hh"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// ELTTTriggerSegment                                                                 //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class ELTTTriggerSegment : public TObject {
public:
  ELTTTriggerSegment();
  virtual ~ELTTTriggerSegment();

ELTTTriggerSegment ( const ELTTTriggerSegment& other );
  virtual void Copy( TObject& other ) const;

  inline Int_t GetNumEvt() const { return fNumEvt; }
  inline void SetNumEvt(Int_t v) { fNumEvt=v; }

  inline Int_t GetMaxCount() const { return fMaxCount; }
  inline void SetMaxCount(Int_t v) { fMaxCount=v; }
  
  inline void SetMaxGtu(Int_t v) { fMaxGtu=v; }
  inline Int_t GetMaxGtu() {return fMaxGtu;}

  inline void SetMaxRow(Int_t v) { fMaxRow=v; }
  inline Int_t GetMaxRow() {return fMaxRow; }

  inline void SetMaxCol(Int_t v) { fMaxCol=v; }
  inline Int_t GetMaxCol() {return fMaxCol;}

  inline void SetMaxChipID(Int_t v) { fMaxChipID=v; }
  inline Int_t GetMaxChipID(){return fMaxChipID;}

  inline void SetMaxDir(Int_t v) { fMaxDir=v; }
  inline Int_t GetMaxDir(){return fMaxDir;}

  inline void SetPdmID(Int_t v) { fPdmID=v; }
  inline Int_t GetPdmID(){return fPdmID;}


private:

  Int_t fNumEvt;//tells how many PDMs were triggering each event
  Int_t fMaxCount;//integrated counts for the triggering event
  Int_t   fMaxGtu;//gtu where the trigger has been generated
  Int_t   fMaxRow; //row of the pixel where the trigger has been generated
   Int_t    fMaxCol;//col of the pixel where the trigger has been generated
 Int_t     fMaxChipID;// PMT where the trigger has been generated
 Int_t     fMaxDir;// direction under which the trigger has been generated
  Int_t fPdmID;
    SetEVisitable()
    ClassDef(ELTTTriggerSegment,1)
};

#endif  /* __ELTTTRIGGERSEGMENT_HH__ */

