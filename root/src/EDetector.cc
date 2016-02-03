// $Id: EDetector.cc 2918 2011-06-10 22:22:31Z mabl $
// Author: A.Thea

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EDetector                                                            *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/

#include "EDetector.hh"
#include "Etypes.hh"

#include "EDetPhoton.hh"
#include "EMacroCellHit.hh"
#include "EMacroCell.hh"
#include "EFee.hh"
#include "EAFee.hh"

ClassImp(EDetector)

const Int_t fgDefClonesSize=10000;

//______________________________________________________________________________
//
//   EDetector
//   =========
//

//______________________________________________________________________________
void EDetector::Streamer(TBuffer &R__b)
{
   // Stream an object of class EDetector.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); 
      if (R__v == 1 || R__v == 2) {
          // dummy variables
          Bool_t copy;
          Bool_t phfill;

          TObject::Streamer(R__b);
          EFillable::Streamer(R__b);
          R__b >> phfill;
          fPhotonFillingMode = phfill ? kAllPhotons : kNoPhotons;
          R__b >> fNightGlowFillable;
          fRunPars.Streamer(R__b);
          fElectronics.Streamer(R__b);
          R__b >> fNumPhotons;
          R__b >> fNumCellHits;
          R__b >> fNumFee;
          R__b >> fNumAFee;
          R__b >> fNumCells;
          R__b >> fFirstTime;
          R__b >> fLastTime;
          fPhotons->Streamer(R__b);
          fMacroCellHits->Streamer(R__b);
          fFee->Streamer(R__b);
          fAFee->Streamer(R__b);
          fMacroCell->Streamer(R__b);
          R__b >> copy;
          R__b.CheckByteCount(R__s, R__c, EDetector::IsA());
      } else if (R__v == 3 ) {
          // dummy variables
          Bool_t phfill;

          TObject::Streamer(R__b);
          EFillable::Streamer(R__b);
          R__b >> phfill;
          fPhotonFillingMode = phfill ? kAllPhotons : kNoPhotons;
          R__b >> fNightGlowFillable;
          fRunPars.Streamer(R__b);
          fElectronics.Streamer(R__b);
          R__b >> fNumPhotons;
          R__b >> fNumCellHits;
          R__b >> fNumFee;
          R__b >> fNumAFee;
          R__b >> fNumCells;
          R__b >> fFirstTime;
          R__b >> fLastTime;
          fPhotons->Streamer(R__b);
          fMacroCellHits->Streamer(R__b);
          fFee->Streamer(R__b);
          fAFee->Streamer(R__b);
          fMacroCell->Streamer(R__b);
          R__b.CheckByteCount(R__s, R__c, EDetector::IsA());
      } else if (R__v == 4 ) {
          // dummy variables
          Int_t dummyEPhotonFillingMode;

          TObject::Streamer(R__b);
          EFillable::Streamer(R__b);
          R__b >> dummyEPhotonFillingMode;
          R__b >> fPhotonFillingMode;
          R__b >> fNightGlowFillable;
          fRunPars.Streamer(R__b);
          fElectronics.Streamer(R__b);
          fStatus.Streamer(R__b);
          R__b >> fNumPhotons;
          R__b >> fNumCellHits;
          R__b >> fNumFee;
          R__b >> fNumAFee;
          R__b >> fNumCells;
          R__b >> fFirstTime;
          R__b >> fLastTime;
          fPhotons->Streamer(R__b);
          fMacroCellHits->Streamer(R__b);
          fFee->Streamer(R__b);
          fAFee->Streamer(R__b);
          fMacroCell->Streamer(R__b);
          R__b.CheckByteCount(R__s, R__c, EDetector::IsA());
      } else {
          EDetector::Class()->ReadBuffer(R__b,this, R__v, R__s, R__c);
      }
   } else {
       EDetector::Class()->WriteBuffer(R__b,this);
   }
}


//______________________________________________________________________________
EDetector::EDetector() {
    //
    // Constructor
    //

    if (TClass::IsCallingNew()) {
        // constructor for memory methods 
        fPhotons = NULL;
        fMacroCellHits = NULL;
        fFee = NULL;
        fAFee = NULL;
        fMacroCell = NULL;
    } else {
        // user defined behavior
        fPhotons = new TClonesArray("EDetPhoton",fgDefClonesSize);
        fMacroCellHits = new TClonesArray("EMacroCellHit",fgDefClonesSize);
        fFee = new TClonesArray("EFee",fgDefClonesSize);
        fAFee = new TClonesArray("EAFee",fgDefClonesSize);
        fMacroCell = new TClonesArray("EMacroCell");
    }

    fPhotonFillingMode = kAllPhotons;
    fNightGlowFillable = kFALSE;

    fNumPhotons     = 0;
    fNumFee         = 0;
    fNumAFee        = 0;
    fNumCells       = 0;
    fNumCellHits    = 0;
    fFirstTime      = kHuge;
    fLastTime       = -kHuge;

}

//______________________________________________________________________________
EDetector::EDetector(const EDetector& other) : TObject() {
    // copy ctor

    other.Copy ( *this );
}

//______________________________________________________________________________
EDetector::~EDetector() {
    // destructor
    
    Clear();
    
    SafeDelete(fMacroCellHits);
    SafeDelete(fFee);
    SafeDelete(fPhotons);
    SafeDelete(fAFee);
    SafeDelete(fMacroCell);

}

//______________________________________________________________________________
void EDetector::Copy( TObject& other) const {
    // copy
    
    TObject::Copy(other);

    EDetector& det = (EDetector&)other;

    // copy det variables
    det.fNumPhotons  = fNumPhotons;
    det.fNumFee      = fNumFee;
    det.fNumAFee     = fNumAFee;
    det.fNumCells    = fNumCells;
    det.fNumCellHits = fNumCellHits;
    det.fFirstTime   = fFirstTime;
    det.fLastTime    = fLastTime;

    // clear tclonesarrays
    SafeDelete(det.fMacroCellHits);
    SafeDelete(det.fPhotons);
    SafeDelete(det.fFee);
    SafeDelete(det.fAFee);
    SafeDelete(det.fMacroCell);

    // create TClonesArray; for copied objects, the static buffer is not used
    det.fMacroCellHits = (TClonesArray*)fMacroCellHits->Clone();
    det.fPhotons       = (TClonesArray*)fPhotons->Clone();
    det.fFee           = (TClonesArray*)fFee->Clone();
    det.fAFee          = (TClonesArray*)fAFee->Clone();
    det.fMacroCell     = (TClonesArray*)fMacroCell->Clone();

    // copy objects
    fElectronics.Copy( det.fElectronics );
    fStatus.Copy( det.fStatus );
    det.fRunPars = fRunPars;

}

//______________________________________________________________________________
void EDetector::Clear( Option_t* opt ) {
    // build header
    
    if ( fMacroCellHits )
      fMacroCellHits->Clear( opt );

    if ( fPhotons )
      fPhotons->Clear( opt );

    if ( fFee )
      fFee->Clear( opt );

    if ( fAFee )
      fAFee->Clear( opt );
    
    if ( fMacroCell )
      fMacroCell->Clear( opt );

    fNumPhotons = 0;
    fNumFee = 0;
    fNumAFee = 0;
    fNumCells = 0;
    fFirstTime = kHuge;
    fLastTime = -kHuge;

    fElectronics.Clear();
    fStatus.Clear();
    TRef dummy;
    fRunPars = dummy;
}

//______________________________________________________________________________
void EDetector::ClearAndShrink( Option_t* opt) {
    //
    //
    //

    Clear( opt );
    if ( fPhotons ) fPhotons->Expand( fgDefClonesSize );
    if ( fMacroCellHits ) fMacroCellHits->Expand( fgDefClonesSize );
    if ( fFee ) fFee->Expand( fgDefClonesSize );
    if ( fAFee ) fAFee->Expand( fgDefClonesSize );
    if ( fMacroCell ) fMacroCell->Expand( 0 );
}

//______________________________________________________________________________
void EDetector::Print( Option_t* ) const {
    
    
    Printf("=> EDetector:");
    Printf("fPhotons entries:       %d",fPhotons->GetEntriesFast());
    Printf("fFee entries:           %d",fFee->GetEntriesFast());
    Printf("fAFee entries:          %d",fAFee->GetEntriesFast());
    Printf("fMacroCellHits entries: %d",fMacroCellHits->GetEntriesFast());
    Printf("fMacroCell entries:     %d",fMacroCell->GetEntriesFast());
    Printf("                          ");
    Printf("fNumPhotons:            %d",fNumPhotons);
    Printf("fNumFee:                %d",fNumFee);
    Printf("fNumAFee:               %d",fNumAFee);
    Printf("fNumCellHits:           %d",fNumCellHits);
    Printf("fNumCells:              %d",fNumCells);
    Printf("                          ");
    Printf("fFirstTime              %f",(Double_t)fFirstTime);
    Printf("fLastTime               %f",(Double_t)fLastTime);
}

