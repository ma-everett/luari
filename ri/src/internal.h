

/* trrt : internal.h */

#ifndef trrt_internal_h
#define trrt_internal_h 1

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include "typedefs.h"
#include <ri.h>

#include <stdio.h>
#include <stdlib.h>

#define VERSION 0.1

typedef struct state_t {

  string_t output_file;
  FILE *f;  
  uint_t not; /* number of tabs */

} state_t;

#define STATE_OUTPUT_TYPE_STDOUT (uint_t) 0
#define STATE_OUTPUT_TYPE_DRIVER (uint_t) 1

#define STATE_DRIVER_TYPE_INTERNAL (uint_t) 0
#define STATE_DRIVER_TYPE_FILE (uint_t) 1

typedef struct object_t {

  uint_t type;
  pointer_t data;

} object_t;

#define OBJECT_TYPE_STATE (uint_t) 0

state_t * grtri_tostate( lua_State *L, uint_t index );
object_t * grtri_pushnewstate( lua_State *L );

/* L U A   R E N D E R M A N   I N T E R F A C E */

/* main.c :
 */

int_t l_RiGetContext( lua_State *L );

int_t l_RiBegin( lua_State *L );
int_t l_RiEnd( lua_State *L );

static const struct luaL_Reg ril_f[] = {
  {"GetContext",l_RiGetContext},
  {"Begin",l_RiBegin},
  {"End",l_RiEnd},
 {NULL,NULL}
};

#endif /* trrt_internal_h */
