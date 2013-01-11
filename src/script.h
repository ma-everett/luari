
/* eon : core : script.h
 */

#ifndef grt_ri_script_h
#define grt_ri_script_h 1

extern "C"
{
  #include "lua.h"
  #include "lauxlib.h"
  #include "lualib.h"
}

#include "memory.h"
#include "reference.h"

namespace grt 
{


#define SCRIPTMETHOD(class, name) {#name, &class::name}
#define SCRIPTMETHODALT(class,alt,name) {#alt, &class::name}

#define SCRIPTOBJECT(class, L) static_cast<class*>(luaL_checkudata(L,-1,class::className));

  template<class T> class Lua
    {
      typedef struct
      {
	T * ptr;
      } pointer;

    public:
      static void Register(lua_State *L) 
	{
	  
	  lua_newtable(L);
	  int methods = lua_gettop(L);

	  luaL_newmetatable(L,T::className);
	  int metatable = lua_gettop(L);

	  lua_pushstring(L, T::className);
	  lua_pushvalue(L,methods);
	  lua_settable(L,LUA_GLOBALSINDEX);
	  
	  lua_pushliteral(L,"__metatable");
	  lua_pushvalue(L,methods);
	  lua_settable(L,metatable);

	  lua_pushliteral(L,"__index");
	  lua_pushvalue(L,methods);
	  lua_settable(L,metatable);

	  lua_pushliteral(L,"__gc");
	  lua_pushcfunction(L,gc);
	  lua_settable(L, metatable);

	  lua_pushstring(L, "__tostring");
	  lua_pushcfunction(L, print);
	  lua_settable(L, metatable);
	  
	  for (const RegType *l = T::methods; l->name; l++) {
	    lua_pushstring(L, l->name);
	    lua_pushlightuserdata(L,(void *)l);
	    lua_pushcclosure(L, thunk, 1);
	    lua_settable(L, methods);
	  }

	  lua_pop(L,2);
	}      
     
      static int constructor(lua_State *L, T * obj)
	{	  
	  pointer *ud = static_cast<pointer*>(lua_newuserdata(L,sizeof(pointer)));
	  ud->ptr = obj;
	  ud->ptr->link( );

	  luaL_getmetatable(L,T::className);
	  lua_setmetatable(L,-2);
	    
	  return 1;
	}

      static int constructor(lua_State *L, Reference<T> obj)
	{
	  return constructor(L,obj.ptr( ) );
	}

      static T * check(lua_State *L, int narg)
	{
	  pointer *ud = static_cast<pointer *>(luaL_checkudata(L,narg, T::className));

	  if (!ud) 
	    luaL_typerror(L,narg,T::className);

	  return ud->ptr;
	}
     
      static int thunk(lua_State *L)
	{
	  T *obj = check(L,1);
	  lua_remove(L,1);

	  RegType *l = static_cast<RegType *>(lua_touserdata(L,lua_upvalueindex(1)));

	  return (obj->*(l->mfunc))(L);	  
	}

      static int gc(lua_State *L)
	{
	  pointer *ud = static_cast<pointer*>(lua_touserdata(L,1));
	  Reference<T> a = ud->ptr;
	  a->ulink( ); 

	  /* a on delete will autocheck if the object needs collecting */
	   
	  return 0;
	}	  

      static int print(lua_State *L)
	{
	  T *obj = check(L,1);
	  lua_pushfstring(L,"%s",T::className);
	  return 1;
	}
          
      struct RegType
      {
	const char *name;
	int(T::*mfunc)(lua_State*);
      };
    };







} 
#endif
