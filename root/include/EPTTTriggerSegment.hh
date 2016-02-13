// $Id$
// Author: fenu2   2009/10/29

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EPTTTriggerSegment                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __EPTTTRIGGERSEGMENT_HH__
#define __EPTTTRIGGERSEGMENT_HH__

#include "TObject.h"
#include "root/include/EFillable.hh"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EPTTTriggerSegment                                                                 //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class EPTTTriggerSegment:public TObject
{
public:
  EPTTTriggerSegment ();
  virtual ~ EPTTTriggerSegment ();

  EPTTTriggerSegment (const EPTTTriggerSegment & other);
  virtual void Copy (TObject & other) const;

  inline Int_t GetNumEvt () const
  {
    return fNumEvt;
  }
  inline void SetNumEvt (Int_t v)
  {
    fNumEvt = v;
  }

  inline Int_t GetMaxCount () const
  {
    return fMaxCount;
  }
  inline void SetMaxCount (Int_t v)
  {
    fMaxCount = v;
  }

  inline void SetMaxGtu (Int_t v)
  {
    fMaxGtu = v;
  }
  inline Int_t GetMaxGtu ()
  {
    return fMaxGtu;
  }

  inline void SetMaxRow (Int_t v)
  {
    fMaxRow = v;
  }
  inline Int_t GetMaxRow ()
  {
    return fMaxRow;
  }

  inline void SetMaxCol (Int_t v)
  {
    fMaxCol = v;
  }
  inline Int_t GetMaxCol ()
  {
    return fMaxCol;
  }

  inline void SetMaxChipID (Int_t v)
  {
    fMaxChipID = v;
  }
  inline Int_t GetMaxChipID ()
  {
    return fMaxChipID;
  }

  inline void SetPdmID (Int_t v)
  {
    fPdmID = v;
  }
  inline Int_t GetPdmID ()
  {
    return fPdmID;
  }
private:

  Int_t fNumEvt;//tells how many PDMs were triggering each event
  Int_t fMaxCount;//integration value
  Int_t fMaxGtu;//GTU where the trig occurred
  Int_t fMaxRow;//EC row of the trigger
  Int_t fMaxCol;//EC col of the trigger
  Int_t fMaxChipID;// EC id of the trigger
  Int_t fPdmID;//PDM id of the trigger

SetEVisitable()
ClassDef (EPTTTriggerSegment, 1)

};

#endif /* __EPTTTRIGGERSEGMENT_HH__ */
