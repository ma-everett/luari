
#ifndef grt_ri_stream_h
#define grt_ri_stream_h 1

#include "script.h"
#include "reference.h"

#include <string>
#include <sstream>

namespace grt
{
  
  class Stream : public ReferenceCounted
    {

    public:

      Stream( );
      ~Stream( );

      Stream * number( double );
      Stream * string( const std::string & );
      Stream * quote( const std::string & );
      Stream * nl( void );
      Stream * ws( void );

      int flush( lua_State *L );

    private:

      std::ostringstream _buffer;

    public:
      
      static const char className[];
      static const Lua<Stream>::RegType methods[];

    };

  typedef Reference<Stream> rStream;

}

#endif
