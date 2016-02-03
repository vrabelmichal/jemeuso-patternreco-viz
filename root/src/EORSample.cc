// $Id: EORSample.cc 3051 2014-01-23 12:04:57Z fenu $
// Author: ale   2005/01/19

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EORSample                                                            *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// EORSample
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "EORSample.hh"
#include <TH2F.h>
#include <TMath.h>
using namespace TMath;

ClassImp(EORSample)

//_____________________________________________________________________________
EORSample::EORSample() : fPsfHist(0) {
    //
    // Constructor
    //

    Clear();
}

//_____________________________________________________________________________
EORSample::~EORSample() {
    //
    // Destructor
    //
}


//______________________________________________________________________________
void EORSample::Clear( Option_t* ) {
    //
    // Clear the sample
    //

    SafeDelete( fPsfHist );
    fThetaIndex    = -1;
    fPhiIndex      = -1;
    fLambdaIndex   = -1;
    fTheta         = -1;
    fPhi           = -1;
    fLambda        = -1;
    fTotalEfficacy = -1;
    fTriggEfficacy = -1;
    fCentroid.SetXYZ(0.,0.,0.);
}


//______________________________________________________________________________
void EORSample::SetPsfHist( TH2F* h ) {
    //
    // 
    //

    SafeDelete( fPsfHist );
    fPsfHist = (TH2F*)h->Clone();

}
//______________________________________________________________________________
TH2F* EORSample::MakePsfHistRotated(Float_t phi) {
    //
    // Returns rotated for the angle phi in deg Psf distribution in XY plane
    // the user must take care to delete this histo him/her self
    if (!fPsfHist) return (TH2F*)NULL;
    
    phi = -phi;

    // get xmin, xmax, ymin, ymax of the original histo

    Float_t xmin_orig = fPsfHist->GetXaxis()->GetXmin();
    Float_t xmax_orig = fPsfHist->GetXaxis()->GetXmax();
    Float_t ymin_orig = fPsfHist->GetYaxis()->GetXmin();
    Float_t ymax_orig = fPsfHist->GetYaxis()->GetXmax();

    // Find a new coordinate of histogram center

    Float_t xcenter_orig = 0.5*(xmin_orig + xmax_orig);
    Float_t ycenter_orig = 0.5*(ymin_orig + ymax_orig);

    Float_t xcenter =  xcenter_orig*Cos(phi) + ycenter_orig*Sin(phi);
    Float_t ycenter = -xcenter_orig*Sin(phi) + ycenter_orig*Cos(phi);

    Float_t DeltaX = 0.5*(xmax_orig - xmin_orig);
    Float_t DeltaY = 0.5*(ymax_orig - ymin_orig);

    Float_t BinWidthX = fPsfHist->GetXaxis()->GetBinWidth(1);
    Float_t BinWidthY = fPsfHist->GetYaxis()->GetBinWidth(1);

    Int_t Nx = fPsfHist->GetNbinsX();
    Int_t Ny = fPsfHist->GetNbinsY();

    // make a new histo and fill it with rotated distribution
   
    TH2F* hRotated = new 
      TH2F("hRotated",Form("Theta=%.2f deg, Phi=%.3f deg",fTheta*RadToDeg(),
			   -phi*RadToDeg()),
	   Nx,xcenter-DeltaX,xcenter+DeltaX,
	   Ny,ycenter-DeltaY,ycenter+DeltaY);

//     hRotated->SetDirectory(0);
    Float_t xn, yn, x, y;
    Int_t nbins = 3;

    for (Int_t ix = 1; ix <= Nx; ix++) {
      Float_t x_orig = fPsfHist->GetXaxis()->GetBinCenter(ix)-0.5*BinWidthX;
      for (Int_t iy = 1; iy <= Ny; iy++) {
	Float_t y_orig = fPsfHist->GetYaxis()->GetBinCenter(iy)-0.5*BinWidthY;
	for (Int_t isx = 0; isx < nbins; isx++) {
	  xn = x_orig + 1.*BinWidthX/nbins*(isx-0.5);
	  for (Int_t isy = 0; isy < nbins; isy++) {
	    yn = y_orig + 1.*BinWidthY/nbins*(isy-0.5);
	    x =  xn*Cos(phi) + yn*Sin(phi);
	    y = -xn*Sin(phi) + yn*Cos(phi);
	    hRotated->Fill(x,y,1.*fPsfHist->GetBinContent(ix,iy)/(nbins*nbins));
	  }
	}
      }
    }	     
    return  hRotated;
}
