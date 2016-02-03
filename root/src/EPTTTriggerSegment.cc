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

//_____________________________________________________________________________
//
// EPTTTriggerSegment
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//
//#include "TObject.h"
#include "EPTTTriggerSegment.hh"
//#include "EEvent.hh"
//#include "Etypes.hh"
//#include <vector>
#include<TH1I.h>


ClassImp (EPTTTriggerSegment)
//_____________________________________________________________________________
  EPTTTriggerSegment::EPTTTriggerSegment ()
{
  //
  // Constructor
  //
}

//_____________________________________________________________________________
EPTTTriggerSegment::~EPTTTriggerSegment ()
{
  //
  // Destructor
  //
}

//_____________________________________________________________________________
EPTTTriggerSegment::EPTTTriggerSegment (const EPTTTriggerSegment & other) : TObject ()
{
  //
  // Copy Constructor
  //
  other.Copy (*this);
}


//_____________________________________________________________________________
void EPTTTriggerSegment::Copy (TObject & other) const {
  //
  // Copy method
  //
  TObject::Copy (other);

  ((EPTTTriggerSegment &) other).SetMaxCount (fMaxCount);
  ((EPTTTriggerSegment &) other).SetNumEvt (fNumEvt);
  ((EPTTTriggerSegment &) other).SetMaxGtu (fMaxGtu);
  ((EPTTTriggerSegment &) other).SetMaxRow (fMaxRow);
  ((EPTTTriggerSegment &) other).SetMaxCol (fMaxCol);
  ((EPTTTriggerSegment &) other).SetMaxChipID (fMaxChipID);
  ((EPTTTriggerSegment &) other).SetPdmID (fPdmID);
}
