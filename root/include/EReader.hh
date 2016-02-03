// $Id: EReader.hh 2187 2005-10-13 14:49:28Z thea $
// Author: ale   2005/06/22

/*****************************************************************************
 * ESAF: Euso Simulation and Analysis Framework                              *
 *                                                                           *
 *  Id: EReader                                                              *
 *  Package: <packagename>                                                   *
 *  Coordinator: <coordinator>                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef __EREADER_HH__
#define __EREADER_HH__

#include <TObject.h>

class EEvent;
class TTree;
class TMap;
class TList;

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// EReader                                                                    //
//                                                                            //  
// <brief class description>                                                  //  
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

class EReader : public TObject {
public:
    EReader();
    virtual ~EReader();

    virtual void Clear(Option_t* opt = "");
     TTree* GetTree() const;
    EEvent* GetEvent() const;
       void AddExt( const char* ext, const char* tname );

     TList* DirFileList(const char*); 
      Int_t Open( const char* files );
      Int_t ConnectFriends();

    
protected:

     TTree* fEvTree;
    EEvent* fEvent;
      TMap* fFriendsExt;

     TList* fExtTrees;
     TList* fFiles;
     TList* fBaseNames;

    ClassDef(EReader,0)
};

inline TTree* EReader::GetTree() const {
    return fEvTree;
}

inline EEvent* EReader::GetEvent() const {
    return fEvent;
}
#endif  /* __EREADER_HH__ */

