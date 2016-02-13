// ESAF : Euso Simulation and Analysis Framework
// $Id: EFillable.hh 2847 2010-10-19 16:03:33Z fenu $
// A.Thea created Jun, 11 2004

#ifndef __EFILLABLE_HH_
#define __EFILLABLE_HH_

#include "Rtypes.h"
#include "TClass.h"

#include "root/include/EFiller.hh"

#define SetEVisitable()     friend class EEventTruthAdder;              \
                            friend class EShowerFiller;                 \
                            friend class EChipTrackTriggerDataAdder;    \
                            friend class ELblTrackTriggerDataAdder;     \
                            friend class EAtmosphereBunchAdder;         \
                            friend class EAtmosphereSingleAdder;        \
                            friend class EDetectorPhotonAdder;          \
                            friend class ESimpleDetectorPhotonAdder;    \
                            friend class ESimpleDetectorPhotoElecAdder; \
                            friend class EDetectorPhotonDataAdder;      \
                            friend class EEventTelemetryAdder;          \
                            friend class EEventFrontEndDataAdder;       \
                            friend class EEventCellStatisticsAdder;     \
                            friend class EPTTTriggerDataAdder;          \
                            friend class ELTTTriggerDataAdder;          \
   			    friend class ECCB_LTTTriggerDataAdder;

class EFillable
{
public:
  EFillable ();

  virtual ~ EFillable ();

  inline virtual Bool_t Fill (EFiller & f);

private:

  ClassDef (EFillable, 1)
};

inline Bool_t
EFillable::Fill (EFiller & f)
{
  // 
  // Fills itself callling EFiller::Fill
  // 

  TString s (f.GetTarget ());

  if (s != IsA ()->GetName ())
    return kFALSE;

  f.Fill (this);

  return kTRUE;
}

#endif /* __EFILLABLE_HH_ */
