// ESAF : Euso Simulation and Analysis Framework
// $Id: EPmtData.hh 1607 2005-03-21 17:13:45Z thea $
//  created May, 24 2004

#ifndef __EPMTDATA_HH_
#define __EPMTDATA_HH_

#include "TObject.h"
#include "root/include/ERunParsFiller.hh"

// EPmtData
// common pmts' data
class EPmtData: public TObject {
public:
    EPmtData();

    ~EPmtData();

    virtual void Copy( TObject& ) const;
    virtual void Clear(Option_t* ="" );

    // getters
    inline Float_t GetPmtSide() const { return fPmtSide;}
    inline Float_t GetPmtHeight() const { return fPmtHeight;}
    inline Float_t GetPadSide() const { return fPadSide;}
    inline Float_t GetPadGap() const { return fPadGap;}
    inline Float_t GetBorderWidth() const { return fBorderWidth;}
    inline Int_t   GetNumPads() const { return fNumPads;}
    inline Int_t   GetNumRows() const { return fNumRows; }
    inline Int_t   GetNumCols() const { return fNumCols; }
    inline Float_t GetQuantum() const { return fQuantum; }
    inline Float_t GetGain() const { return fGain; }
    inline Float_t GetGainSigma() const { return fGainSigma; }
    inline Float_t GetWidth() const { return fWidth; }
    inline Float_t GetGtuLength() const { return fGtuLength; }
    
    // setters
    inline void SetPmtSide( Float_t side ) { fPmtSide = side; }
    inline void SetPmtHeight( Float_t h ) { fPmtHeight = h; }
    inline void SetPadSide( Float_t side ) { fPadSide = side; }
    inline void SetPadGap( Float_t gap ) { fPadGap = gap ; }
    inline void SetBorderWidth( Float_t bwidth ) { fBorderWidth = bwidth; }
    inline void SetNumPads( Int_t pads ) { fNumPads = pads; }
    inline void SetNumRows( Int_t rows ) { fNumRows = rows; }
    inline void SetNumCols( Int_t cols ) { fNumCols = cols; }
    inline void SetQuantum( Float_t q ) { fQuantum = q; }
    inline void SetGain( Float_t g ) { fGain = g; }
    inline void SetGainSigma( Float_t gsigma ) { fGainSigma = gsigma; }
    inline void SetWidth( Float_t width ) { fWidth = width; }
    inline void SetGtuLength( Float_t gtulen ) { fGtuLength = gtulen; }

    inline Int_t Pmt( Int_t uid ) const;
    // return pmt id from channel unique id

    inline Int_t Channel( Int_t uid ) const;
    // return channel id [0-(fNumPads-1)] from pixel id

    inline Int_t Col( Int_t uid ) const;
    // return colum number from uid
    
    inline Int_t Row( Int_t uid ) const;
    // return row number from uid
    
    inline Float_t X( Int_t uid ) const;
    // x coord. of pixel(uid) center in pmt ref frame 
    
    inline Float_t Y( Int_t uid ) const;
    // y coord. of pixel(uid) center in pmt ref frame
    
    inline Int_t ChCol( Int_t ch ) const;
    // return colum of channel ch
    
    inline Int_t ChRow( Int_t ch ) const;
    // return row of channel ch

    inline Float_t ChX( Int_t ch ) const;
    // x coord of the channel ch in pmt ref frame

    inline Float_t ChY( Int_t ch ) const;
    // y coord of the channel ch in pmt ref frame

private:

    // static variables of PmtGeometry
    Float_t fPmtSide;               // pmt side length 
    Float_t fPmtHeight;             // pmt height
    Float_t fPadSide;               // pmt pad side length
    Float_t fPadGap;                // width of gap among pads
    Float_t fBorderWidth;           // width of the pmt's dead border
    Int_t   fNumPads;               // number of pixels per pmt
    Int_t   fNumRows;               // number of rows
    Int_t   fNumCols;               // number of columns

    // static variables of Photomultiplier
    Float_t fQuantum;               // quantum efficiency
    Float_t fGain;                  // nominal gain
    Float_t fGainSigma;             // gain spread
    Float_t fWidth;                 // time width
    Float_t fGtuLength;             // gtu length (ns)

    ClassDef(EPmtData,1)

    ERunParsVisitable()
};


inline Int_t EPmtData::Pmt( Int_t uid ) const {
    return (uid-1)/GetNumPads()+1;
}

inline Int_t EPmtData::Channel( Int_t uid ) const {
    return (uid-1) % GetNumPads();
}

inline Int_t EPmtData::Col( Int_t uid ) const {
    return ChCol(Channel( uid ));
}

inline Int_t EPmtData::Row( Int_t uid ) const {
    return ChRow(Channel( uid ));
}

inline Float_t EPmtData::X( Int_t uid ) const {
    return ChX(Channel(uid));
}

inline Float_t EPmtData::Y( Int_t uid ) const {
    return ChY(Channel(uid)); 
}

inline Int_t EPmtData::ChCol( Int_t ch ) const {
    return ch % GetNumCols();
}

inline Int_t EPmtData::ChRow( Int_t ch ) const {
    return ch / GetNumCols();
}

inline Float_t EPmtData::ChX( Int_t ch ) const {
    return -fPmtSide/2.+fBorderWidth
        +fPadGap*(ChCol(ch))
        +fPadSide*(ChCol(ch)+0.5);
}

inline Float_t EPmtData::ChY( Int_t ch ) const {
    return -(-fPmtSide/2.+fBorderWidth
        +fPadGap*(ChRow(ch))
        +fPadSide*(ChRow(ch)+0.5));
}
#endif  /* __EPMTDATA_HH_ */

