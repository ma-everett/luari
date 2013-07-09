

#include "script.h"
#include "reference.h"
#include "memory.h"

#include "context.h"
#include "stream.h"
#include "rib.h"

#include <iostream>
#include <vector>

using namespace grt;

const double VERSION = 0.2;


int lgetversion( lua_State *L )
{
  lua_pushnumber(L,VERSION);
  return 1;
}

int lnewcontext( lua_State *L )
{
  std::string name = luaL_checkstring(L,1);

  rContext c = new(alloc_aligned( sizeof(Context))) Context( name );
  
  if (!c)
    {
      lua_pushnil(L);
      lua_pushstring(L,"ERROR, no memory for allocating new context!");
      return 2;
    }
  else
    return Lua<Context>::constructor(L, c);
}



static const struct luaL_Reg ril_f[] = {
  {"newContext",lnewcontext},
  {"getVersion",lgetversion},
  {NULL,NULL}
};

int load( lua_State * L )
{

  /* Register all the script interfaces : */
  Lua<Context>::Register(L);
  Lua<Stream>::Register(L);
  Lua<RIB>::Register(L);

  luaL_newmetatable(L, "grt_ri");
  lua_pushvalue(L,-1);
  lua_setfield(L,-2,"__index");
  luaL_setfuncs(L,ril_f,0); //lua 5.2
  // was luaL_register(L,"grt",ril_f); for lua 5.1

  return 1;
}


/* FIXME: must be a better/safer way of unmangling the function name?!!! */

extern "C" {

  int luaopen_grt_ri ( lua_State * L )
    {
      return load( L );
    }
}

