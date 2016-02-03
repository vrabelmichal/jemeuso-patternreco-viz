// ESAF : Euso Simulation and Analysis Framework
// $Id: LinkDef.hh 2847 2010-10-19 16:03:33Z fenu $
// A. Thea created Apr, 27 2004
// this file is needed by rootcint to make an additional C++ that
// must be compiled and linked to use the EusoEvent class in root

#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

// namespaces
#pragma link C++ namespace sou;

// Global Enums
#pragma link C++ enum EPhotonType;
#pragma link C++ enum EDetectorSystem;
#pragma link C++ enum EFocalSurfaceElement;
#pragma link C++ enum ETriggerTypeIdentifier;
#pragma link C++ enum EHeader::EStatus;
#pragma link C++ enum EDetector::EPhotonFillingMode;

// Fillers
#pragma link C++ class EFiller+;
#pragma link C++ class EFillable+;

// utility class
#pragma link C++ class EReader+;

// EEvent Classes
#pragma link C++ class EEvent+;
#pragma link C++ class EEvTreeLink+;
#pragma link C++ class EHeader-;
#pragma link C++ class ETruth-;
#pragma link C++ class EPhoton+;

#pragma link C++ class EAtmosphere+;
#pragma link C++ class EBunchPhotons+;
#pragma link C++ class ESinglePhoton+;

#pragma link C++ class EShower+;
#pragma link C++ class EShowerStep+;

#pragma link C++ class EDetector-;
#pragma link C++ class EDetStatus+;
#pragma link C++ class EGeometry+;
#pragma link C++ class EElectronics+;
#pragma link C++ class EDetPhoton+;
#pragma link C++ class EMacroCellHit+;
#pragma link C++ class EMacroCell+;
#pragma link C++ class EFee+;
#pragma link C++ class EAFee+;

#pragma link C++ class EChipTrackTrigger+;
#pragma link C++ class EChipTrackSegment+;
#pragma link C++ class EPTTTrigger+;
#pragma link C++ class EPTTTriggerSegment+;
#pragma link C++ class ELTTTrigger+;
#pragma link C++ class ELTTTriggerSegment+;
#pragma link C++ class ECCB_LTTTrigger+;
#pragma link C++ class ECCB_LTTTriggerSegment+;
#pragma link C++ class ELblTrackTrigger+;
#pragma link C++ class ELblTrackSegment+;

#pragma link C++ class ESimpleDetector+;
#pragma link C++ class ESimpDetPhoton+;
#pragma link C++ class EPhotoElectron+;

// ERunParameters Classes
#pragma link C++ class EAnglePixelMap+;
#pragma link C++ class EPmtGeo+;
#pragma link C++ class EPmtData+;
#pragma link C++ class ERunParameters-;
#pragma link C++ class ERunParsFiller+;
#pragma link C++ class ETriggPars+;
#pragma link C++ class EChipTriggPars+;

// Optics Response Classes
#pragma link C++ class EOpticsResponse+;
#pragma link C++ class EORHeader+;
#pragma link C++ class EORSample+;
#endif

