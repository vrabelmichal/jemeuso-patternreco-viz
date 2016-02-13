// $Id: ETriggPars.hh 2263 2005-10-24 13:17:06Z thea $
// Author: Alessandro Thea   2005/10/18

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: ETriggPars                                                           *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __ETRIGGPARS_HH__
#define __ETRIGGPARS_HH__

#include <TObject.h>
#include "root/include/Etypes.hh"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// ETriggPars                                                                 //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class ETriggPars : public TObject {
public:
    ETriggPars();
    ETriggPars( ETriggPars& );
    virtual ~ETriggPars();
    
    virtual void Copy(TObject&) const;
    virtual void Clear(Option_t* ="");

    inline virtual ETriggerTypeIdentifier GetId() const { return fId; }
    inline virtual const char* GetName() const { return fName; }
    inline void SetId( ETriggerTypeIdentifier id ) { fId=id; }
    inline void SetName( const char* name ) { fName=name; }

protected:
    ETriggerTypeIdentifier fId;
    const char* fName; 

    ClassDef(ETriggPars,1)
};

#endif  /* __ETRIGGPARS_HH__ */

