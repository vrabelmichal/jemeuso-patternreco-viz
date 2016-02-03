// $Id: ESimpDetPhoton.cc 2620 2006-03-24 16:27:06Z moreggia $
// Author: Sylvain Moreggia   2006/03/21

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ESimpDetPhoton                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// ESimpDetPhoton
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "ESimpDetPhoton.hh"
#include "Etypes.hh"

ClassImp(ESimpDetPhoton)

//_____________________________________________________________________________
ESimpDetPhoton::ESimpDetPhoton() {
    //
    // Constructor
    //

}

//_____________________________________________________________________________
ESimpDetPhoton::~ESimpDetPhoton() {
    //
    // Destructor
    //
}

//_____________________________________________________________________________
ESimpDetPhoton::ESimpDetPhoton(const ESimpDetPhoton& other) {
    //
    // copy ctor
    //
    
    other.Copy( *this );
}

//_____________________________________________________________________________
ESimpDetPhoton::ESimpDetPhoton(const EPhoton& other) {
    //
    // copy ctor
    //
    
    Clear();
    other.Copy( *this );
}

//_____________________________________________________________________________
void ESimpDetPhoton::Copy( TObject& other) const {
    //
    // copy 
    //
    
    ((ESimpDetPhoton&)other).fType           = fType;
    ((ESimpDetPhoton&)other).fShowerPosX     = fShowerPosX;
    ((ESimpDetPhoton&)other).fShowerPosY     = fShowerPosY;
    ((ESimpDetPhoton&)other).fShowerPosZ     = fShowerPosZ;

    ((ESimpDetPhoton&)other).fTheta          = fTheta;           
    ((ESimpDetPhoton&)other).fPhi            = fPhi;            
    ((ESimpDetPhoton&)other).fLambda         = fLambda;        
    ((ESimpDetPhoton&)other).fTime           = fTime;         

    ((ESimpDetPhoton&)other).fAtmoHistory    = fAtmoHistory;
    ((ESimpDetPhoton&)other).fFate           = fFate;        
    ((ESimpDetPhoton&)other).fPosX           = fPosX;      
    ((ESimpDetPhoton&)other).fPosY           = fPosY;      
    ((ESimpDetPhoton&)other).fPosZ           = fPosZ;
}

//_____________________________________________________________________________
void ESimpDetPhoton::Clear( Option_t* opt) {

    EPhoton::Clear(opt);

    fShowerPosX     = -kHuge;
    fShowerPosY     = -kHuge; 
    fShowerPosZ     = -kHuge;

    fAtmoHistory    = -1000; 
    fFate           = -1000;
}


