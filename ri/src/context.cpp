
#include "context.h"
#include <iostream>
#include "memory.h"

namespace grt
{

  Context::Context( const std::string & name )
  {
    _name = name;

    /* create a stream object */
    _stream = new(alloc_aligned(sizeof(Stream))) Stream;
    
    /* create the ri interface object */
    _rib = new(alloc_aligned(sizeof(RIB))) RIB ( _stream.ptr( ) );

  }
   
  Context::~Context( )
  {

  }

  std::string & 
  Context::getName( void )
  {
    return _name;
  }

  int
  Context::getStream( lua_State * L )
  {
    return Lua<Stream>::constructor(L,_stream);
  }

  int 
  Context::getRIBInterface( lua_State * L )
  {
    return Lua<RIB>::constructor(L,_rib);
  }

  const char Context::className[] = "Context";
  const Lua<Context>::RegType Context::methods[] = 
    {
      SCRIPTMETHOD(Context,getStream),
      SCRIPTMETHOD(Context,getRIBInterface),
      { 0,0 }};
}
