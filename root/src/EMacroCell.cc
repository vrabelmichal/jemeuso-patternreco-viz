// ESAF : Euso Simulation and Analysis Framework
// $Id: EMacroCell.cc 3066 2014-04-11 17:46:37Z fenu $
//  created May, 23 2004

#include "EMacroCell.hh"

ClassImp(EMacroCell)

//_____________________________________________________________________________
EMacroCell::EMacroCell() {
    // ctor

    Clear();
}

//_____________________________________________________________________________
EMacroCell::EMacroCell(const EMacroCell& other) : TObject() {
    // copy ctor

    other.Copy( *this );
}

//_____________________________________________________________________________
EMacroCell::~EMacroCell() {
    // dtor

    //Clear();
}

//_____________________________________________________________________________
void EMacroCell::Copy( TObject& other) const {
    // copy

    TObject::Copy( other );

    ((EMacroCell&)other).fMCId         = fMCId;
    ((EMacroCell&)other).fNumChips     = fNumChips;
    ((EMacroCell&)other).fNumPixels    = fNumPixels;
    ((EMacroCell&)other).fNumCounts    = fNumCounts;
    ((EMacroCell&)other).fNumFastOrs   = fNumFastOrs;
    ((EMacroCell&)other).fHasTriggered = fHasTriggered;
    ((EMacroCell&)other).fGtuTrigger   = fGtuTrigger;
    ((EMacroCell&)other).fTriggerWord  = fTriggerWord;
    ((EMacroCell&)other).fTrgWords     = fTrgWords;
    ((EMacroCell&)other).fTrgIds       = fTrgIds;
    ((EMacroCell&)other).fGtuTriggerCCB   = fGtuTriggerCCB;
    ((EMacroCell&)other).fTrigDirCCB   = fTrigDirCCB;
    ((EMacroCell&)other).fTrigECRowCCB  = fTrigECRowCCB;
    ((EMacroCell&)other).fTrigECColCCB = fTrigECColCCB;
    ((EMacroCell&)other).fTrigChipIDCCB = fTrigChipIDCCB;
    ((EMacroCell&)other).fTrigPDMIDCCB = fTrigPDMIDCCB;
    ((EMacroCell&)other).fTrigMaxCTSCCB = fTrigMaxCTSCCB;
    ((EMacroCell&)other).fTrigMaxUID_CCB = fTrigMaxUID_CCB;

}

//_____________________________________________________________________________
void EMacroCell::Clear( Option_t* opt ) {
    //clear
    fMCId           = 0; 
    fNumChips       = 0;
    fNumPixels      = 0;
    fNumCounts      = 0;
    fNumFastOrs     = 0; 
    fHasTriggered   = 0;
    fGtuTrigger     = 0;
    fTriggerWord    = 0;
    fGtuTriggerCCB = -10;
    fTrigDirCCB =-10;
    fTrigECRowCCB=-10;
    fTrigECColCCB=-10;
    fTrigChipIDCCB=-10;
    fTrigPDMIDCCB=-10;
    fTrigMaxCTSCCB=-10;
    fTrigMaxUID_CCB=-10;
    fTrgWords.Set(0);
    fTrgIds.Set(0);
}

//_____________________________________________________________________________
Int_t EMacroCell::GetWord(ETriggerTypeIdentifier id) const {
    // get the word of a specific trigger
    if ( fTrgIds.GetSize()==0 ) return 0;
    for(Int_t i(0); i<fTrgIds.GetSize(); i++) {
        if ( fTrgIds.At(i) == (Int_t)id ) {
            return fTrgWords.At(i);
        }
    }
    return 0;
}
