// ESAF : Euso Simulation and Analysis Framework
// $Id: ERunParameters.cc 2918 2011-06-10 22:22:31Z mabl $
// M. Pallavicini, A. Thea created Sep, 19 2003

#include "root/include/ERunParameters.hh"

#include "TGeoManager.h"
#include "TGeoMaterial.h"
#include "TGeoMedium.h"
#include "TGeoVolume.h"
#include "TGeoMatrix.h"
#include <TClass.h>
#include <TList.h>
ClassImp(ERunParameters)

//TClonesArray* ERunParameters::fgPmts = NULL;
//ERunParameters* ERunParameters::fgCurrent = NULL;

using namespace TMath;

// class ERunParameters


//______________________________________________________________________________
void ERunParameters::Streamer(TBuffer &R__b)
{
    // Stream an object of class ERunParameters.

    UInt_t R__s, R__c;
    if (R__b.IsReading()) {
        Version_t R__v = R__b.ReadVersion(&R__s, &R__c);
        if (R__v == 1) {
            TObject::Streamer(R__b);
            R__b >> fNumPmts;
            fPmts->Streamer(R__b);
            fChipNightGlowRates.Streamer(R__b);
            fPmtData.Streamer(R__b);
            fAnglePixelMap.Streamer(R__b);
            R__b.CheckByteCount(R__s, R__c, ERunParameters::IsA());
        } else {
            ERunParameters::Class()->ReadBuffer(R__b, this, R__v, R__s, R__c);
        }
    } else {
        ERunParameters::Class()->WriteBuffer(R__b,this);
    }
}

//_____________________________________________________________________________
ERunParameters::ERunParameters() : fNumPmts(0), fTriggPars(0) {
    // ctor

    if ( TClass::IsCallingNew() ) {
        fPmts = 0;
    } else {
        fPmts = new TClonesArray("EPmtGeo", 7000);
    }
}

//_____________________________________________________________________________
ERunParameters::ERunParameters( const ERunParameters& o ) : fNumPmts(0), fTriggPars(0) {
    // ctor

    fPmts = 0;
    o.Copy(*this);

}

//_____________________________________________________________________________
ERunParameters::~ERunParameters() {
    // dtor

    if ( fPmts ) {
    fPmts->Delete();
    delete fPmts;
    }


//    if ( GetCurrent() == this ) SetCurrent( 0 );
}


//______________________________________________________________________________
void ERunParameters::Copy( TObject& other ) const {
    //
    // Copy this to other
    //

    ERunParameters& run = (ERunParameters&)other;

    TObject::Copy(other);

    // clean other's arrays
    SafeDelete(run.fPmts);

    run.fNumPmts = fNumPmts;
    fAnglePixelMap.Copy(run.fAnglePixelMap);
    fPmtData.Copy(run.fPmtData);

    run.fPmts = (TClonesArray*)fPmts->Clone();

}

//_____________________________________________________________________________
void ERunParameters::Clear( Option_t *opt ) {
    // clean params

    if ( fPmts ) fPmts->Clear("C");

    fNumPmts = 0;

    fPmtData.Clear();
    fAnglePixelMap.Clear();
}

//______________________________________________________________________________
Float_t ERunParameters::GetNightGlowRate( Int_t feid ) const {
    //
    // return the mean nightglow rate in the microcell field
    //

    if ( feid<1 || feid>fChipNightGlowRates.GetSize() ) return 0;

    return fChipNightGlowRates[--feid];
}

//______________________________________________________________________________
Float_t ERunParameters::GetNightGlowRateByUId( Int_t uid ) const {

    Int_t feid = FrontEndChip(uid);

    if (!feid) return 0;

    return fChipNightGlowRates[--feid];
}

//_____________________________________________________________________________
const EPmtGeo* ERunParameters::GetPmtGeo(Int_t id) const {
    if ( IsValidPmt( id ) )
        return (EPmtGeo*)fPmts->At( id-1 );

    Error("GetPmtGeo(i)", "bad index (%d) returning 0", id);
    return 0;
}

//_____________________________________________________________________________
const EPmtGeo* ERunParameters::GetPmtGeoByUId(Int_t uid) const {
    // return pmt geo object
    Int_t pmtId;
    if ( (pmtId = Pmt( uid )) == 0 )
        return 0;

    return GetPmtGeo( pmtId );
}

//_____________________________________________________________________________
Int_t ERunParameters::Pmt( Int_t uid ) const {
    //
    // return Pmt id from Pixel unique id
    //

    if ( !GetPixelMap().IsValid( uid ) )
        return 0;

    // estimate the index of pmt inside fPmts
    Int_t pmtId = GetPmtData().Pmt(uid);

    // check
    EPmtGeo* pmt = (EPmtGeo*)fPmts->At(pmtId-1);
    if (  pmt == 0 ||
          uid < pmt->GetStartUniqueId() ||
          uid > pmt->GetLastUniqueId() ) {

        Error("Pmt(i)", "bad index (%d) returning 0", uid);
        return 0;
    }

    return pmtId;
}

//_____________________________________________________________________________
Int_t ERunParameters::ElementaryCell( Int_t uid ) const {
    // return EC id from unique id

    Int_t pmtId = Pmt( uid );

    if ( pmtId == 0 ) return 0;

    return GetPmtGeo(pmtId)->GetEC();
}

//_____________________________________________________________________________
Int_t ERunParameters::FrontEndChip( Int_t uid ) const {
    // return Fee chip id from unique id

    Int_t pmtId = Pmt( uid );

    if ( pmtId == 0 ) return 0;

    return GetPmtGeo(pmtId)->GetFee();
}

//_____________________________________________________________________________
Int_t ERunParameters::MacroCell( Int_t uid ) const {
    // return MC number form unique id

    Int_t pmtId = Pmt( uid );

    if ( pmtId == 0 ) return 0;

    return GetPmtGeo(pmtId)->GetMC();
}

//_____________________________________________________________________________
const ETriggPars* ERunParameters::GetTriggPars( const char* name ) const {
    //
    // Return the trigger parameters given the trigger engine name
    //

    if (!fTriggPars) return 0;
    return (ETriggPars*)fTriggPars->FindObject(name);
}

//_____________________________________________________________________________
const ETriggPars* ERunParameters::GetTriggPars( ETriggerTypeIdentifier id ) const {
    //
    // Return the trigger parameters given the trigger id
    //

    if (!fTriggPars) return 0;
    TListIter itTriggPars(fTriggPars);
    ETriggPars *tp;

    Int_t i(0);
    while ( i++ < fTriggPars->GetEntries() ) {
        tp = (ETriggPars*)itTriggPars();
        if ( tp->GetId() == id ) return tp;
    }

    return 0;

}

//_____________________________________________________________________________
TVector3 ERunParameters::PmtCorner( Int_t id, Int_t k ) const {
    // Position of the pmts corners

    TVector3 dummy(-100000,-100000,-100000);
    if ( !IsValidPmt( id ) )
        return dummy;

    Float_t dX, dY;
    switch( k ) {
        case kTopLeftCorner:
            dX = -0.5;
            dY = 0.5;
            break;
        case kTopRightCorner:
            dX = 0.5;
            dY = 0.5;
            break;
        case kBottomRightCorner:
            dX = 0.5;
            dY = -0.5;
            break;
        case kBottomLeftCorner:
            dX = -0.5;
            dY = -0.5;
            break;
        default:
            Error("PmtCorner(i,k)","bad index k");
            return dummy;
    }

    const EPmtGeo* pmt = GetPmtGeo(id);
    EPmtData data = GetPmtData();

    dX *= data.GetPmtSide();
    dY *= data.GetPmtSide();

    dummy = pmt->GetCenter();

    dummy += pmt->GetXAxis()*dX;
    dummy += pmt->GetYAxis()*dY;

    return dummy;
}

//_____________________________________________________________________________
TVector3 ERunParameters::PixelCenter( Int_t uid ) const {
    // center of the pixel on the focal surface

    TVector3 dummy(-100000,-100000,-100000);
    if ( !GetPixelMap().IsValid( uid ) )
        return dummy;


    const EPmtGeo* pmt = GetPmtGeo(Pmt(uid));
    EPmtData data = GetPmtData();

    dummy = pmt->GetCenter();

    dummy += pmt->GetXAxis()*data.X(uid);
    dummy += pmt->GetYAxis()*data.Y(uid);

    return dummy;
}

//_____________________________________________________________________________
TVector3 ERunParameters::PixelCorner( Int_t uid, Int_t k ) const {
    // Position of the pixel corners

    TVector3 dummy(-100000,-100000,-100000);
    if ( !GetPixelMap().IsValid( uid ) )
        return dummy;

    Float_t dX, dY;
    switch( k ) {
        case kTopLeftCorner:
            dX = -0.5;
            dY = 0.5;
            break;
        case kTopRightCorner:
            dX = 0.5;
            dY = 0.5;
            break;
        case kBottomRightCorner:
            dX = 0.5;
            dY = -0.5;
            break;
        case kBottomLeftCorner:
            dX = -0.5;
            dY = -0.5;
            break;
        default:
            Error("PixelCorner(i,k)","bad index k");
            return dummy;
    }

    const EPmtGeo* pmt = GetPmtGeo(Pmt(uid));
    EPmtData data = GetPmtData();

    dX *= data.GetPadSide();
    dY *= data.GetPadSide();

    dummy = PixelCenter(uid);

    dummy += pmt->GetXAxis()*dX;
    dummy += pmt->GetYAxis()*dY;

    return dummy;
}

//_____________________________________________________________________________
void ERunParameters::DrawFocalSurface() {

    EPmtData d = GetPmtData();

    Float_t pcb_height = 3.;
    Double_t worldx = 1300.;
    Double_t worldy = 1300.;
    Double_t worldz = 1000.;

//     Float_t pcb_height = 3.;
//     Double_t worldx = 150.;
//     Double_t worldy = 150.;
//     Double_t worldz = 50.;

    //--- Definition of a simple geometry
    TGeoManager *geom = new TGeoManager("euso", "Euso geometry");

    //--- define some materials
    TGeoMaterial *matVacuum = new TGeoMaterial("Vacuum", 0,0,0);
    TGeoMaterial *matAl = new TGeoMaterial("Al", 26.98,13,2.7);
    //--- define some media
    TGeoMedium *Vacuum = new TGeoMedium("Vacuum",1, matVacuum);
    TGeoMedium *Al = new TGeoMedium("Root Material",2, matAl);

    //--- define the transformations
    TGeoTranslation *trpcb = new TGeoTranslation(0., 0., -d.GetPmtHeight()/2);
    TGeoTranslation *tr2 = new TGeoTranslation( d.GetPmtSide()/2.,
                                                d.GetPmtSide()/2., pcb_height/2.);
    TGeoTranslation *tr3 = new TGeoTranslation( d.GetPmtSide()/2.,
                                               -d.GetPmtSide()/2., pcb_height/2.);
    TGeoTranslation *tr4 = new TGeoTranslation(-d.GetPmtSide()/2.,
                                               -d.GetPmtSide()/2., pcb_height/2.);
    TGeoTranslation *tr5 = new TGeoTranslation(-d.GetPmtSide()/2.,
                                                d.GetPmtSide()/2., pcb_height/2.);

    //--- make the top container volume
    TGeoVolume *top = geom->MakeBox("Top",Vacuum, worldx, worldy, worldz);
    geom->SetTopVolume(top);

    //--- make the elementary cell
    TGeoVolume *elcell = geom->MakeBox("Top",Vacuum, d.GetPmtSide(),
                                                     d.GetPmtSide(),
                                                     (d.GetPmtHeight()+pcb_height)/2.);
    elcell->SetLineColor(kRed);
    TGeoVolume *pcb = geom->MakeBox("PCB",Al, d.GetPmtSide(),
                                              d.GetPmtSide(),
                                              pcb_height/2.);
    pcb->SetLineColor(kGreen);
    elcell->AddNode(pcb, 1, trpcb);

    //--- make the pmt
    TGeoVolume *pmt = geom->MakeBox("PMT",Al, d.GetPmtSide()/2.,
                                              d.GetPmtSide()/2.,
                                              d.GetPmtHeight()/2.);
    pmt->SetLineColor(29);
    TGeoVolume *hull = geom->MakeBox("HULL",Al, d.GetPmtSide()/2.,
                                              d.GetPmtSide()/2.,
                                              d.GetPmtHeight()/2.);
    hull->SetLineColor(38);
    pmt->AddNode(hull, 1, new TGeoTranslation(0.,0.,0.));
    TGeoVolume *pixel = geom->MakeBox("PIXEL",Al, d.GetPadSide()/2.,
                                                  d.GetPadSide()/2.,
                                                  0.1);
    pixel->SetLineColor(29);
    Int_t row(0), col(0);
    for(Int_t k(0); k<d.GetNumPads(); k++){
        if ( row >= d.GetNumRows() ) row = 0;
        if ( col >= d.GetNumCols() ) {
            col = 0;
            row++;
        }

        Float_t dx=-d.GetPmtSide()/2.+d.GetBorderWidth()+
           col*(d.GetPadSide()+d.GetPadGap())+d.GetPadSide()/2.;
        Float_t dy=d.GetPmtSide()/2.-d.GetBorderWidth()-
           row*(d.GetPadSide()+d.GetPadGap())-d.GetPadSide()/2.;

        pmt->AddNode(pixel, k, new TGeoTranslation(dx, dy,
                                                   d.GetPmtHeight()/2.));
        col++;
    }

    elcell->AddNode(pmt, 1, tr2);
    elcell->AddNode(pmt, 2, tr3);
    elcell->AddNode(pmt, 3, tr4);
    elcell->AddNode(pmt, 4, tr5);

    TGeoRotation rot;
    TGeoTranslation tr;

    for(Int_t i(1); i<= GetNumPmts()/4; i++) {
        TVector3 center(0,0,0);
        TVector3 xax = GetPmtGeo(4*(i-1)+1)->GetXAxis();
        TVector3 yax = GetPmtGeo(4*(i-1)+1)->GetYAxis();
        TVector3 zax = GetPmtGeo(4*(i-1)+1)->GetNorm();

        for(Int_t j(1); j<5;j++)
            center += GetPmtGeo(4*(i-1)+j)->GetCenter();


        center *= 0.25;
        center -= 0.5*(d.GetPmtHeight()+pcb_height)*zax.Unit();
        rot.SetAngles(xax.Theta()*TMath::RadToDeg(), xax.Phi()*TMath::RadToDeg(),
                     yax.Theta()*TMath::RadToDeg(), yax.Phi()*TMath::RadToDeg(),
                     zax.Theta()*TMath::RadToDeg(), zax.Phi()*TMath::RadToDeg());
        tr.SetTranslation(center.X(),
                          center.Y(),
                          center.Z());
        TGeoHMatrix h = tr*rot;
        top->AddNode(elcell,i,new TGeoHMatrix(h));
    }
    geom->CloseGeometry();
    top->SetLineColor(kMagenta);
    geom->SetVisLevel(1);
    geom->SetTopVisible();
    top->Draw("gl");
}

//_____________________________________________________________________________
/*Bool_t ERunParameters::IsInsidePixel(Int_t uid, const TVector2& point) const {
    //
    // returns kTRUE if given point is inside the surface of pixel with ID = uid
    // returns kFALSE otherwise

    TVector2 xax = GetPmtGeo(Pmt(uid))->GetXAxis().XYvector().Unit();
    TVector2 yax = GetPmtGeo(Pmt(uid))->GetYAxis().XYvector().Unit();

    TVector2 ref = point - PixelCenter(uid).XYvector();

    Float_t x = ref*xax;
    Float_t y = ref*yax;

    return Abs (x) <= GetPmtData().GetPadSide()/2 && Abs (y) <= GetPmtData().GetPadSide()/2) ;

}   */

//_____________________________________________________________________________
Bool_t ERunParameters::IsInsidePixel(Int_t uid, const TVector2& point) const {
    //
    // returns kTRUE if given point is inside the surface of pixel with ID = uid
    // returns kFALSE otherwise
    //
    TVector3 xax = GetPmtGeo(Pmt(uid))->GetXAxis();
    TVector3 yax = GetPmtGeo(Pmt(uid))->GetYAxis();
    TVector2 ref = point - PixelCenter(uid).XYvector();
    Float_t x = (ref.X()*xax[0]+ref.Y()*xax[1])/(xax[0]*xax[0]+xax[1]*xax[1]);
    Float_t y = (ref.X()*yax[0]+ref.Y()*yax[1])/(yax[0]*yax[0]+yax[1]*yax[1]);
    return (Abs(x)<=GetPmtData().GetPadSide()/2 && Abs(y)<=GetPmtData().GetPadSide()/2);
}
