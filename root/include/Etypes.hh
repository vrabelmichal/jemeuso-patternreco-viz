// $Id: Etypes.hh 2847 2010-10-19 16:03:33Z fenu $
// Author: A.Thea   May, 23 2004

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: Etypes                                                               *
 *  Package: Rootm                                                           *
 *  Coordinator: Marco.Pallavicini                                           *
 *                                                                           *
 *****************************************************************************/

#ifndef __ETYPES_HH__
#define __ETYPES_HH__

#include "Rtypes.h"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// Etypes                                                                     //
//                                                                            //
// Code wise defined enums and variables                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

const Float_t kHuge = 1e20;

// Photon type identifier
enum EPhotonType {
    kFluorescence             = 1,
    kDirectCherenkov          = 2,
    kBackCherenkov            = 3
};

// Detector subsystem identifier
enum EDetectorSystem {
    kUndefined                = 0,
    kNotInside                = 1,
    kBaffle                   = 2,
    kOptics                   = 3,
    kFocalPlane               = 4,
    kWalls                    = 5,
    kEarth                    = 6,
    kG4FocalSurface           = 7
};

enum EFocalSurfaceElement {
    kOpticalAdapter           = 1,
    kPmt                      = 2
};

// Trigger type identifier
enum ETriggerTypeIdentifier {
    kNoTrigger                 = 0,
    kPersistencyTrigger        = BIT(0),
    kContiguityTrigger         = BIT(1),
    kChipTrackingTrigger       = BIT(2),
    kChipTrackingTrigger0      = BIT(3),
    kChipTrackingTrigger1      = BIT(4),
    kChipTrackingTrigger2      = BIT(5),
    kChipTrackingTrigger3      = BIT(6),
    kChipTrackingTrigger4      = BIT(7),
    kSignalChipTrackingTrigger = BIT(8),
    kCellTrackingTrigger       = BIT(9),
    kLblChipTrackingTrigger    = BIT(10),
    kPTTTrigger                = BIT(11),
    kLTTTrigger                = BIT(12),
    kCCB_LTTTrigger            = BIT(13)
};

#endif  /* __ETYPES_HH__ */

