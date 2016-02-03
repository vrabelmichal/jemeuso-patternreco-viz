// $Id: ETriggPars.cc 2263 2005-10-24 13:17:06Z thea $
// Author: Alessandro Thea   2005/10/18

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ETriggPars                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// ETriggPars
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "ETriggPars.hh"

ClassImp(ETriggPars)

//_____________________________________________________________________________
ETriggPars::ETriggPars() {
    //
    // Constructor
    //
    Clear();
}

//_____________________________________________________________________________
ETriggPars::ETriggPars( ETriggPars& other ) {
    //
    // Copy constructor
    //

    other.Copy(*this);
}

//______________________________________________________________________________
void ETriggPars::Copy( TObject& other ) const {
//
//
//
    
    TObject::Copy(other);

    ((ETriggPars&)other).fId = fId;
    ((ETriggPars&)other).fName = fName;
}


//_____________________________________________________________________________
ETriggPars::~ETriggPars() {
    //
    // Destructor
    //
}

//_____________________________________________________________________________
void ETriggPars::Clear( Option_t* opt ) {
    //
    // Clear
    //
    
    fName = 0;
    fId = (ETriggerTypeIdentifier)0;
}
