// $Id: EGeometry.cc 2372 2005-11-14 22:42:00Z thea $
// Author: Alessandro Thea   2005/11/14

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EGeometry                                                              *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

//_____________________________________________________________________________
//
// EGeometry
//
// <extensive class description>
//
//   Config file parameters
//   ======================
//
//   <parameter name>: <parameter description>
//   -Valid options: <available options>
//

#include "EGeometry.hh"

ClassImp(EGeometry)

//_____________________________________________________________________________
EGeometry::EGeometry() : fFoV(0), fRadius(0), fPosX(0), fPosY(0), fPosZ(0) {
    //
    // Constructor
    //

}

//_____________________________________________________________________________
EGeometry::~EGeometry() {
    //
    // Destructor
    //
}

//______________________________________________________________________________
void EGeometry::Clear( Option_t* opt ) {
    //
    // Reset the geometry
    //

    fFoV = 0;
    fRadius = 0;

    fPosX = 0;
    fPosY = 0;
    fPosZ = 0;

    SetXEulerAngles(0.,0.,0.);
}
