// ESAF : Euso Simulation and Analysis Framework
// $Id: EPhoton.cc 2918 2011-06-10 22:22:31Z mabl $
// Author: A.Thea

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EPhoton                                                              *
 *  Package: SimuEvent                                                       *
 *  Coordinator: Alessandro.Thea                                             *
 *                                                                           *
 *****************************************************************************/

#include "root/include/EPhoton.hh"
#include "root/include/Etypes.hh"

ClassImp(EPhoton)

//_____________________________________________________________________________
EPhoton::EPhoton(): TObject() {
    // 
    // Constructor
    // 

    Clear();
}

//_____________________________________________________________________________
EPhoton::~EPhoton() {
    // 
    // Destructor
    // 
}

//_____________________________________________________________________________
EPhoton::EPhoton(const EPhoton& other) : TObject() {
    // 
    // Copy ctor
    // 
    
    other.Copy( *this );
}

//_____________________________________________________________________________
void EPhoton::Copy( TObject& other) const {
    //
    // Copy 
    //
    
    ((EPhoton&)other).fType           = fType;
    ((EPhoton&)other).fTheta          = fTheta;           
    ((EPhoton&)other).fPhi            = fPhi;            
    ((EPhoton&)other).fLambda         = fLambda;        
    ((EPhoton&)other).fTime           = fTime;         

    ((EPhoton&)other).fPosX           = fPosX;      
    ((EPhoton&)other).fPosY           = fPosY;      
    ((EPhoton&)other).fPosZ           = fPosZ;
}

//_____________________________________________________________________________
void EPhoton::Clear( Option_t* opt) {

    fType           = 0; 
    fTheta          = -100; 
    fPhi            = -100;
    fLambda         = -100;
    fTime           = -100;
    fPosX           = -kHuge;
    fPosY           = -kHuge;
    fPosZ           = -kHuge;

}


