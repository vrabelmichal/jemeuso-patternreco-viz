// $Id: EOpticsResponse.hh 3051 2014-01-23 12:04:57Z fenu $
// Author: ale   2005/01/19

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EOpticsResponse                                                      *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __EOPTICSRESPONSE_HH__
#define __EOPTICSRESPONSE_HH__

#include <TObject.h>

class TFile;
class TTree;
class EORSample;
class EORHeader;
class TH1F;
class TH2F; 
class TClonesArray;

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EOpticsResponse                                                            //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class EOpticsResponse : public TObject {
public:
    EOpticsResponse( const char* filename );
    virtual    ~EOpticsResponse();
    
    // Getters
    EORHeader*  GetHeader() { return fHeader; }
    EORSample*  GetSample() { return fSample; }
    TTree*      GetTree()   { return fTree; }
    Bool_t      GetEntry(Float_t th, Float_t phi, Float_t lam);    // read entry with given Theta and Lambda
    // Makers
    TH2F*       MakePsfHist(Float_t, Float_t, TH1F*);  // returnes a mixture of Psf distributions for the entry spectrum
    TH2F*       MakePsfHist(Float_t, Float_t, Float_t);// returnes a mixture of Psf distributions for the entry spectrum
    
    
    void      Clear( Option_t* ="");
private:

    TFile        *fFile;
    TTree        *fTree;

    EORSample    *fSample;
    EORHeader    *fHeader;
 
    TH2F*         fPsf;                       // Psf distribution for the given spectrum
    TClonesArray* fPoints;                    // temp container
    
    ClassDef(EOpticsResponse,0)
};

#endif  /* __EOPTICSRESPONSE_HH__ */

