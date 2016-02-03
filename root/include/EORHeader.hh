// $Id: EORHeader.hh 3051 2014-01-23 12:04:57Z fenu $
// Author: ale   2005/01/19

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EORHeader                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __EORHEADER_HH__
#define __EORHEADER_HH__

#include <TObject.h>
#include <TString.h>


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EORHeader                                                                  //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class EORHeader : public TObject {
public:
    EORHeader();
    virtual ~EORHeader();

    inline void    SetBins(Int_t nth, Int_t nphi, Int_t nl)            { fBinsTheta = nth; fBinsPhi = nphi; fBinsLambda = nl;}
    inline void    SetPsfBins(Int_t i)                     { fPsfBins = i;}
    inline void    SetNrays( Int_t n )                     { fNrays = n; }
    inline void    SetThetaMin( Float_t th )               { fThetaMin = th; }
    inline void    SetThetaMax( Float_t th )               { fThetaMax = th; }
    inline void    SetPhiMin( Float_t phi )                { fPhiMin = phi; }
    inline void    SetPhiMax( Float_t phi )                { fPhiMax = phi; }
    inline void    SetLambdaMin( Float_t wl )              { fLambdaMin = wl; }
    inline void    SetLambdaMax( Float_t wl )              { fLambdaMax = wl; }
    inline void    SetThetaIndexMin( Int_t i )             { fThetaIndexMin = i; }
    inline void    SetThetaIndexMax( Int_t i )             { fThetaIndexMax = i; }
    inline void    SetPhiIndexMin( Int_t i )               { fPhiIndexMin = i; }
    inline void    SetPhiIndexMax( Int_t i )               { fPhiIndexMax = i; }
    inline void    SetLambdaIndexMin( Int_t i )            { fLambdaIndexMin = i; }
    inline void    SetLambdaIndexMax( Int_t i )            { fLambdaIndexMax = i; }
    

    inline void    SetDiscRadius( Float_t r )              { fDiscRadius = r; }
    inline void    SetEusoRadius( Float_t r )              { fEusoRadius = r; }
    inline void    SetRmax( Float_t r )                    { fRmax = r; }
    inline void    SetTriggDiam( Float_t d )               { fTriggDiam = d; }

    inline void    SetOpticsName( const char* name )       { fOpticsName = name; }
    inline void    SetIdealSurfaceName( const char* name ) { fIdealSurfaceName = name; }
    // getters
    inline Int_t   GetBinsTheta()              { return fBinsTheta;}
    inline Int_t   GetBinsPhi()                { return fBinsPhi;}
    inline Int_t   GetBinsLambda()             { return fBinsLambda;}
    inline Int_t   GetPsfBins()                { return fPsfBins;}
    inline Int_t   GetNrays()                  { return fNrays; }
    inline Float_t GetThetaMin()               { return fThetaMin; }
    inline Float_t GetThetaMax()               { return fThetaMax; }
    inline Float_t GetPhiMin()                 { return fPhiMin; }
    inline Float_t GetPhiMax()                 { return fPhiMax; }
    inline Float_t GetLambdaMin()              { return fLambdaMin; }
    inline Float_t GetLambdaMax()              { return fLambdaMax; }
    inline Int_t   GetThetaIndexMin()          { return fThetaIndexMin; }
    inline Int_t   GetThetaIndexMax()          { return fThetaIndexMax; }
    inline Int_t   GetPhiIndexMin()            { return fPhiIndexMin; }
    inline Int_t   GetPhiIndexMax()            { return fPhiIndexMax; }
    inline Int_t   GetLambdaIndexMin()         { return fLambdaIndexMin; }
    inline Int_t   GetLambdaIndexMax()         { return fLambdaIndexMax; }

    inline Float_t GetDiscRadius()             { return fDiscRadius; }
    inline Float_t GetEusoRadius()             { return fEusoRadius; }
    inline Float_t GetRmax()                   { return fRmax; }
    inline Float_t GetTriggDiam()              { return fTriggDiam; }

    inline const char* GetOpticsName()         { return fOpticsName.Data(); }
    inline const char* GetIdealSurfaceName()   { return fIdealSurfaceName.Data(); }

private:
    Int_t   fBinsTheta;
    Int_t   fBinsPhi;
    Int_t   fBinsLambda;
    Int_t   fPsfBins;
    Int_t   fNrays;
    Float_t fThetaMin;
    Float_t fThetaMax;
    Float_t fPhiMin;
    Float_t fPhiMax;
    Float_t fLambdaMin;
    Float_t fLambdaMax;
    Int_t   fThetaIndexMin;
    Int_t   fThetaIndexMax;
    Int_t   fPhiIndexMin;
    Int_t   fPhiIndexMax;
    Int_t   fLambdaIndexMin;
    Int_t   fLambdaIndexMax;    
    Float_t fDiscRadius;
    Float_t fEusoRadius;
    Float_t fRmax;
    Float_t fTriggDiam;

    TString fOpticsName;
    TString fIdealSurfaceName;


    ClassDef(EORHeader,1)
};

#endif  /* __ORHEADER_HH__ */

