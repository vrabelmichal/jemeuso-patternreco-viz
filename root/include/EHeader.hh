// $Id: EHeader.hh 2648 2006-03-31 16:04:00Z thea $
//  Author: M.Pallavicini

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EHeader                                                              *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/

#ifndef __EHEADER_HH__
#define __EHEADER_HH__

#include "TObject.h"
#include "TRandom.h"
 
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EHeader                                                                    //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


class EHeader : public TObject {
public:
    EHeader();
    // ctor

    EHeader(const EHeader&);
    // copy ctor

    virtual ~EHeader();
    // dtor

    virtual void Clear( Option_t* = "" );
    // clear object

    virtual void Copy( TObject& ) const;
    // copy from an existing object
    
    inline Int_t   GetNum() const { return fNum; }
    inline Int_t   GetRun() const { return fRun; }
    const char*    GetRunName() const { return fRunName.Data(); }
    const TRandom* GetRandom() const { return fRandom; }
    inline UInt_t  GetStatus() const { return fStatus; }
    inline const char* GetStatusMsg() const { return fStatusMsg.Data(); }

    inline void SetNum( Int_t v ) { fNum=v; }
    inline void SetRun( Int_t v ) { fRun=v; }
           void SetRandom( const TRandom* );
    inline void SetRunName( const char* name ) { fRunName = name ? name : ""; }
    inline void SetStatus( UInt_t s ) { fStatus=s; }
    inline void SetStatus( UInt_t s, const char* msg ) { fStatus=s; SetStatusMsg(msg); }
    inline void SetStatusMsg( const char* msg ) { fStatusMsg = msg ? msg : ""; }

    enum EStatus {
        kOK        = 0, 
        kFailed    = 1
    };

    ClassDef(EHeader,3)

private:
    Int_t    fNum;      // event number
    Int_t    fRun;      // run number
    TString  fRunName;  // run name
    TRandom* fRandom;   // random number generator
    UInt_t   fStatus;   // status code  [success (0), failure (code)]  
    TString  fStatusMsg;
    
    // trigger infos may go here or in EusoTree; tbd
};

#endif  /* __EHEADER_HH__ */

