// ESAF : Euso Simulation and Analysis Framework
// $Id: EMacroCell.hh 3066 2014-04-11 17:46:37Z fenu $
//  created May, 23 2004

#ifndef __EMACROCELL_HH__
#define __EMACROCELL_HH__

#include "TObject.h"
#include "TArrayI.h"
#include "Etypes.hh"
#include "EFillable.hh"


// MacroCell data
class EMacroCell : public TObject {
public:
    EMacroCell();
    // ctor

    EMacroCell(const EMacroCell&);
    // copy ctor

    virtual ~EMacroCell();
    // dtor

    virtual void Copy( TObject& ) const;
    // copy this to a new obj

    virtual void Clear( Option_t* = "" );
    // clear data
    
    inline Int_t GetMCId() const { return fMCId; }
    inline Int_t GetNumChips() const { return fNumChips; }
    inline Int_t GetNumPixels() const { return fNumPixels; }
    inline Int_t GetNumCounts() const { return fNumCounts; }
    inline Int_t GetNumFastOrs() const { return fNumFastOrs; }
    inline Int_t HasTriggered() const { return fHasTriggered; }
    inline Int_t GetGtuTrigger() const { return fGtuTrigger; }
    inline Int_t GetTriggerWord() const { return fTriggerWord; }
    inline TArrayI GetTrgWords() const { return fTrgWords; }
    inline TArrayI GetTrgIds() const { return fTrgIds; }
    inline Int_t GetGtuTriggerCCB() const { return fGtuTriggerCCB; }
    inline Int_t GetTrigDirCCB() const { return fTrigDirCCB; }
    inline Int_t GetTrigECRowCCB() const { return fTrigECRowCCB; }
    inline Int_t GetTrigECColCCB() const { return fTrigECColCCB; }
    inline Int_t GetTrigChipIDCCB() const { return fTrigChipIDCCB; }
    inline Int_t GetTrigPDMIDCCB() const { return fTrigPDMIDCCB; }
    inline Int_t GetTrigMaxCTSCCB() const { return fTrigMaxCTSCCB; }
    inline Int_t GetTrigMaxUID_CCB() const { return fTrigMaxUID_CCB; }

    Int_t GetWord(ETriggerTypeIdentifier) const;
    
    inline void SetMCId(Int_t val) {fMCId=val;}
    inline void SetNumChips(Int_t val) {fNumChips=val;}
    inline void SetNumPixels(Int_t val) {fNumPixels=val;}
    inline void SetNumCounts(Int_t val) {fNumCounts=val;}
    inline void SetNumFastOrs(Int_t val) {fNumFastOrs=val;}
    inline void SetHasTriggered(Int_t val) {fHasTriggered=val;}
    inline void SetGtuTrigger(Int_t val) {fGtuTrigger=val;}
    inline void SetTriggerWord(Int_t val) {fTriggerWord=val;}
    inline void SetTrgWords(Int_t size, const Int_t *array) {fTrgWords.Set(size,array);}
    inline void SetTrgIds(Int_t size, const Int_t *array) {fTrgIds.Set(size,array);} 
    inline void SetGtuTriggerCCB(Int_t val) {fGtuTriggerCCB=val;}
    inline void SetTrigDirCCB(Int_t val) {fTrigDirCCB=val;}
    inline void SetTrigECRowCCB(Int_t val) {fTrigECRowCCB=val;}
    inline void SetTrigECColCCB(Int_t val) {fTrigECColCCB=val;}
    inline void SetTrigChipIDCCB(Int_t val) {fTrigChipIDCCB=val;}
    inline void SetTrigPDMIDCCB(Int_t val) {fTrigPDMIDCCB=val;}
    inline void SetTrigMaxCTSCCB(Int_t val) {fTrigMaxCTSCCB=val;}
    inline void SetTrigMaxUID_UID(Int_t val) {fTrigMaxUID_CCB=val;}

    ClassDef(EMacroCell,1)
        
private:
    Int_t fMCId;           // macroCell id
    Int_t fNumChips;       // number of front end chips giving signal
    Int_t fNumPixels;      // number of pixels with at least one photon
    Int_t fNumCounts;      // number of counts detected by chips (not necessarily mCell)
    Int_t fNumFastOrs;     // number of fast or counts detected by macroCell
    Int_t fHasTriggered;   // trigger condition occured
    Int_t fGtuTrigger;     // gtu number when trigger occurred
  Int_t fTriggerWord;    // trigger engine identifier word (bitfield)
  Int_t fGtuTriggerCCB,fTrigDirCCB,fTrigECRowCCB,fTrigECColCCB,fTrigChipIDCCB,fTrigPDMIDCCB,fTrigMaxCTSCCB,fTrigMaxUID_CCB;
    //specific trigger words for engines running multiple configurations
    TArrayI fTrgWords;     // trigger words
    TArrayI fTrgIds;       // corresponding trigger ids

    SetEVisitable()
};


#endif  /* __EMACROCELL_HH__ */

