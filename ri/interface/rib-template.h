#ifndef grt_ri_rib_h
#define grt_ri_rib_h 1

/* THIS IS A AUTOMAGICALLY GENERATED FILE! */

#include "script.h"
#include "reference.h"
#include "stream.h"
#include <string>

namespace grt
{
  
  class RIB : public ReferenceCounted
    {

    public:

      RIB( Stream * );
      ~RIB( );

      <FUNCTIONS>
      
	 /* hand-coded functions */
	 int Comment( lua_State * L );
      int Hint( lua_State * L );

      int togglePrettyPrint( lua_State *L );
      
    private:
      
      /* parses and generates the output */
      int format( const std::string &, lua_State * );

      
    public:
      
      static const char className[];
      static const Lua<RIB>::RegType methods[];

    protected:

      rStream _stream;
      int _tabs;
      bool _prettyPrint;
    };

  typedef Reference<RIB> rRIB;

}

#endif
