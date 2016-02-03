// $Id: EHeader.cc 2648 2006-03-31 16:04:00Z thea $
// Author: M.Pallavicini

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EHeader                                                              *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/

//______________________________________________________________________________
//
//  EHeader
//  

#include "EHeader.hh"
#include <TClass.h>

ClassImp(EHeader)

//______________________________________________________________________________
void EHeader::Streamer(TBuffer &R__b)
{
   // Stream an object of class EHeader.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
       Version_t R__v = R__b.ReadVersion(&R__s, &R__c); 
       if (R__v == 1) { 
           TObject::Streamer(R__b);
           R__b >> fNum;
           R__b >> fRun;
           fRunName.Streamer(R__b);
           R__b >> fRandom;
           R__b.CheckByteCount(R__s, R__c, EHeader::IsA());
           // old runs, only successes
           fStatus = kOK;
           // no mesg
           fStatusMsg = "";
       } else if ( R__v == 2 ) {
           Int_t dummyEStatus;
           R__b >> dummyEStatus;
           R__b >> fNum;
           R__b >> fRun;
           fRunName.Streamer(R__b);
           R__b >> fRandom;
           R__b >> fStatus;
           fStatusMsg.Streamer(R__b);
           R__b.CheckByteCount(R__s, R__c, EHeader::IsA());
       } else {
           EHeader::Class()->ReadBuffer(R__b, this, R__v, R__s, R__c);
       }
   } else {
       EHeader::Class()->WriteBuffer(R__b, this);
   }

}

//_____________________________________________________________________________
EHeader::EHeader() : fNum(-1), fRun(-1), fRandom(0), fStatus(kOK) {
    //
    // Constructor
    //

}

//_____________________________________________________________________________
EHeader::EHeader(const EHeader& other) : TObject(other) {
    // 
    // Copy ctor
    //

   other.Copy( *this );
}

//_____________________________________________________________________________
EHeader::~EHeader() {
    // 
    // Destructor
    // 

    Clear();
}

//_____________________________________________________________________________
void EHeader::Copy( TObject& other ) const {
    //
    // Copy
    //

    TObject::Copy(other);

    EHeader& h = (EHeader&)other;
    h.fNum = fNum;
    h.fRun = fRun;
    h.SetRandom(fRandom); 
    h.fStatus = fStatus;
    h.fStatusMsg = fStatusMsg;
}


//_____________________________________________________________________________
void EHeader::Clear( Option_t * ) {
    //
    // Clear object
    //

    fNum = -1;
    fRun = -1;

    SafeDelete(fRandom);

    fStatus = kOK; 
    fStatusMsg="";
}

//______________________________________________________________________________
void EHeader::SetRandom( const TRandom* rndm ) { 
    //
    // Set random number generator
    //

    if ( fRandom ) delete fRandom;

    fRandom = (TRandom*)rndm->Clone();
}
