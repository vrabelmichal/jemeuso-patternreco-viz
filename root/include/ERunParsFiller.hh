// ESAF : Euso Simulation and Analysis Framework
// $Id: ERunParsFiller.hh 2257 2005-10-24 09:08:00Z pesce $
// Alessandro Thea created  created Oct, 24 2003
// Euso Root Parameters "Visitor"
// This class is an abstract interface to any class that can fill EEvent 
// variables; 

#ifndef __EUSORUNPARSFILLER_HH_
#define __EUSORUNPARSFILLER_HH_

#define ERunParsVisitable() friend class ERunParsFiller; \
                            friend class ERunParsPixelMapFiller; \
                            friend class ERunParsPmtsFiller; \
                            friend class EChipTriggParsFiller;

#include "Rtypes.h"

class ERunParameters;

class ERunParsFiller {
public:
    // ctor
    ERunParsFiller();
   
    // dtor
    virtual ~ERunParsFiller();

    // abstract interface to any fill operation of root file
    virtual void Fill( ERunParameters* ) = 0;

private:

    ClassDef(ERunParsFiller,1)
};

#endif  /* __EUSORUNPARSFILLER_HH_ */

