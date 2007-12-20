
/* THIS IS AN AUTOMAGICALLY GENERATED FILE! */

#include "rib.h"

namespace grt
{

  RIB::RIB( Stream * s )
  {
    _stream = s;
    _tabs = 0;
    _prettyPrint = true;
  }

  RIB::~RIB( )
  {

  }

  <FUNCTIONS>
  

  /* hand-coded functions */
  int 
  RIB::Comment( lua_State * L )
  {
    if (_prettyPrint)
      for (unsigned int t = 0; t < _tabs; t++)
	_stream->string( "\t" );

    _stream->string( "#" )->ws( );
   
    if (lua_gettop(L) >= 1)
      {
	_stream->string( luaL_checkstring(L,1) );
      }

    _stream->nl( );
    return 0;
  }

  int 
  RIB::Hint( lua_State * L )
  {
    if (_prettyPrint)
      for (unsigned int t = 0; t < _tabs; t++)
	_stream->string( "\t" );

    _stream->string( "##" )->ws( );
   
    if (lua_gettop(L) >= 1)
      {
	_stream->string( luaL_checkstring(L,1) );
      }

    _stream->nl( );
    return 0;
  }    

  int 
  RIB::togglePrettyPrint( lua_State * L )
  {
    /* ignore any variables */
    _prettyPrint = !_prettyPrint;

    lua_pushnumber(L,_prettyPrint);
    return 1;
  }

  int 
  RIB::format( const std::string & n, lua_State * L )
  {
    if (_prettyPrint)
      for (unsigned int t = 0; t < _tabs; t++)
	_stream->string( "\t" );


    /* the name: */
    _stream->string( n )->ws( );


    int top = lua_gettop(L);

    if (top == 0)
      {
	_stream->nl( );
	return 0;
      }
    else
      { /* parse all the attributes and print to stream */

	for (unsigned int op= 1; op <= top; op++)
	  {
	    if (lua_isnumber(L,op))
	      {
		_stream->number( luaL_checknumber(L,op) )->ws( );
	      }
	    else if (lua_isstring(L,op))
	      {
		_stream->quote( luaL_checkstring(L,op) )->ws( );
	      }
	  }

	_stream->nl( );
	return 0;
      }

  }
 
  const char RIB::className[] = "RIB";
  const Lua<RIB>::RegType RIB::methods[] = 
    {      
      <METHODS>
      SCRIPTMETHOD(RIB,Comment),
      SCRIPTMETHOD(RIB,Hint),
      SCRIPTMETHOD(RIB,togglePrettyPrint),
      { 0,0 }};
}
