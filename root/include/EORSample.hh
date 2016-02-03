// $Id: EORSample.hh 3051 2014-01-23 12:04:57Z fenu $
// Author: ale   2005/01/19

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EORSample                                                            *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __EORSAMPLE_HH__
#define __EORSAMPLE_HH__

#include <TObject.h>
#include <TVector3.h>

class TH2F;

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EORSample                                                                  //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class EORSample : public TObject {
public:
    EORSample();
    virtual ~EORSample();

    virtual void   Clear( Option_t* = "");

    // Setters
    inline void    SetThetaIndex(Int_t n)        { fThetaIndex = n;}
    inline void    SetPhiIndex(Int_t n)          { fPhiIndex = n;}
    inline void    SetLambdaIndex(Int_t n)       { fLambdaIndex = n;}   
    inline void    SetTheta(Float_t theta)       { fTheta = theta;}
    inline void    SetPhi(Float_t phi)           { fPhi = phi;}
    inline void    SetLambda(Float_t lambda)     { fLambda = lambda;}
    inline void    SetTotalEfficacy(Float_t eff) { fTotalEfficacy = eff;}
    inline void    SetTriggEfficacy(Float_t eff) { fTriggEfficacy = eff;}
    inline void    SetCentroid( const TVector3& v ) { fCentroid = v; }
           void    SetPsfHist(TH2F*);
     // Getters
    inline TH2F*   GetPsfHist() const { return fPsfHist;}
    inline Int_t   GetThetaIndex() const { return fThetaIndex;}
    inline Int_t   GetPhiIndex() const { return fPhiIndex;}
    inline Int_t   GetLambdaIndex() const { return fLambdaIndex;}
    inline Float_t GetTheta() const { return fTheta;}
    inline Float_t GetPhi() const { return fPhi;}
    inline Float_t GetLambda() const { return fLambda;}
    inline Float_t GetTotalEfficacy() const { return fTotalEfficacy;}
    inline Float_t GetTriggEfficacy() const { return fTriggEfficacy;}
    inline const TVector3& GetCentroid() const { return fCentroid; }
    // Makers
    TH2F*          MakePsfHistRotated(Float_t ph);
    
private:

    Int_t    fThetaIndex;      // Theta index for faster access
    Int_t    fPhiIndex;      // Phi index for faster access
    Int_t    fLambdaIndex;     // Lambda index for faster access
    Float_t  fTheta;           // Incident Theta angle in rad
    Float_t  fPhi;             // Incident Phi angle in rad
    Float_t  fLambda;          // Light wavelength in nm
    Float_t  fTotalEfficacy;   // Optics Global Efficacy
    Float_t  fTriggEfficacy;   // Optics Triggering Efficacy
    TVector3 fCentroid;        // position of the centroid on the fs

    TH2F*    fPsfHist;         // XY distribution of efficacy

    ClassDef(EORSample,1)
};

#endif  /* __ORSAMPLE_HH__ */

