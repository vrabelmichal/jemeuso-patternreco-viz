// $Id$
// Author: fenu2   2009/10/29

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ECCB_LTTTriggerSegment                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __ECCB_LTTTRIGGERSEGMENT_HH__
#define __ECCB_LTTTRIGGERSEGMENT_HH__

#include "TObject.h"
#include "EFillable.hh"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// ECCB_LTTTriggerSegment                                                                 //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class ECCB_LTTTriggerSegment : public TObject {
public:
  ECCB_LTTTriggerSegment();
  virtual ~ECCB_LTTTriggerSegment();

ECCB_LTTTriggerSegment ( const ECCB_LTTTriggerSegment& other );
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

  Int_t fNumEvt;// tells how many PDMs are triggering in one event
  Int_t fMaxCount;//maximum counts integrated in casse of trigger
  Int_t fMaxGtu;// gtu of maximum trigger
  Int_t fMaxRow;// EC row of trigger
  Int_t fMaxCol;// EC column of trigger 
  Int_t fMaxChipID;// Chip (Elementary Cell) where the trigger happened
  Int_t fMaxDir;// direction under which the maximum intergration was obtained
  Int_t fPdmID;// PDM id where the trigger happened 
    SetEVisitable()
    ClassDef(ECCB_LTTTriggerSegment,1)

//friend class ThirdLevelTrigger;


};

#endif  /* __EBERTATRIGGERSEGMENT_HH__ */

