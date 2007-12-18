
/* grt : ri : main.c
 */

#include "internal.h"
#include "pmem.h"
#include "prettyprint.h"
#include "lri.h" /* automagically created */

state_t * 
grtri_tostate( lua_State *L, uint_t index ) {

  object_t *obj = NULL;
  obj = (object_t *)luaL_checkudata(L,index,"state");

  if (obj) {
    
    if (obj->type == OBJECT_TYPE_STATE) {

      return obj->data;
    }
  }

  return NULL;
}

object_t * 
grtri_pushnewstate( lua_State *L ) {

  object_t *obj = NULL;
  obj = (object_t *)lua_newuserdata(L,sizeof(object_t));

  if (obj) {

    obj->type = OBJECT_TYPE_STATE;
    obj->data = NULL;
  }

  luaL_getmetatable(L,"state");
  lua_setmetatable(L,-2);

  return obj;
}


/* R E N D E R M A N  I N T E R F A C E */

/* RiGetContext( void )
 */
int_t 
l_RiGetContext( lua_State *L ) {

   object_t *obj = grtri_pushnewstate(L);
  
  if (obj) {

    state_t *state = (state_t *)grtri_malloc(sizeof(state_t));

    state->output_file = NULL; /* check for errors */
    state->f = NULL; 
    state->not = 0;   

    obj->data = (pointer_t)state;
  }

  return 1;
}

/* RiBegin ( RtToken name )
 */
int_t l_RiBegin( lua_State *L ) {

  state_t * state = grtri_tostate(L,1);

  RtToken name = RI_NULL;
  
  if (lua_gettop(L) == 2) {
    
     name = (RtToken)luaL_checkstring(L,2);
     
     /* open the file */
     state->output_file = name;
     state->f = fopen( name, "w" );
     
     /* FIXME: add error checking here please! */
  } else {

    state->f = stdout;
  }
  
  return 0;
}

/* RiEnd ( void )
 */
int_t l_RiEnd( lua_State *L ) { 

  state_t * state = grtri_tostate(L,1);

  if (state->f) {

    fclose(state->f);
    /* FIXME: add error checking here please! */
  }
  
  
  return 0;
}

  
/* L U A   I N T E R F A C E   C O N S T R U C T I O N */

int_t luaopen_grt_ri ( lua_State *L ) {

  luaL_newmetatable(L, "state");
  lua_pushvalue(L,-1);
  lua_setfield(L,-2,"__index");
  luaL_register(L, NULL, ril_m);
  luaL_register(L, "grt", ril_f);

  return 1;
}

