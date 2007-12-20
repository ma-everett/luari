

#ifndef grt_ri_context_h
#define grt_ri_context_h 1

#include "script.h"
#include "reference.h"
#include "stream.h"

/* include an automagically generated interface : */
#include "rib.h"

#include <string>
#include <vector>

namespace grt
{
  
  class Context : public ReferenceCounted
    {

    public:

      Context( const std::string & );
      ~Context( );

      std::string & getName( void );

      
    private:
      
      int test( lua_State *L );


      
      int getStream( lua_State *L );
      int getRIBInterface( lua_State *L );

      /* LUA BINDING */
    public:
      
      static const char className[];
      static const Lua<Context>::RegType methods[];

    protected:

      std::string _name;
      
      rStream _stream;
      rRIB _rib;

    };

  typedef Reference<Context> rContext;
  typedef std::vector<Context *> ContextList;
  typedef std::vector<Reference<Context> > rContextList;

}

#endif
