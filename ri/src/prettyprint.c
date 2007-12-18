

#include "prettyprint.h"
#include "internal.h"

/* print nicely tabbed lines 
 */
void_t
pretty_tab( lua_State *L ) {

  state_t *state = grtri_tostate(L,1);

  uint_t op = 0;

  if (state) {

    if (state->not == 0) 
      return;

    for( ; op < state->not; op++)
      fprintf( state->f, "\t" );
  }
}

#define ZERO 0.00f

/* print argument values from a lua stack
 */
void_t
print_args_f( lua_State *L, string_t tail ) {

  state_t * state = grtri_tostate(L,1);
  uint_t op = 2;
  uint_t top = (lua_gettop(L) - 1);

  for (; op < (top + 2); op++) {

    /* check whether number or string */
    if (lua_isnumber(L,op)) {
      
      /* number, so check if integer or real (double) */
      if (luaL_checknumber(L,op)) {
	
	fprintf(state->f, "%.2f", (RtFloat)lua_tonumber(L,op));
	
      } else {
       	
	/* print integer : */
	fprintf(state->f,"%d", (RtInt)luaL_checkinteger(L,op));
	}
      
    } else if (lua_isstring(L,op)) { 
      

      /* to allow [ & ] characters without placing string quotes we
       * need to check for them */
      RtToken c = (RtToken)luaL_checkstring(L,op);

      if ((c[0] == '[') || (c[0] == ']')) {

	/* print string */
	fprintf(state->f, "%s", (RtToken)luaL_checkstring(L,op));
      } else {

      	/* print string */
	fprintf(state->f, "\"%s\"", (RtToken)luaL_checkstring(L,op));
      }
    }

    fprintf(state->f," ");
  }      

  if (tail)    
    fprintf(state->f,"%s", tail);
  

  fprintf(state->f,"\n");

}

/* print argument values from a lua stack
 */
void_t
print_args( lua_State *L, string_t tail ) {

  state_t * state = grtri_tostate(L,1);
  uint_t op = 2;
  uint_t top = (lua_gettop(L) - 1);

  for (; op < (top + 2); op++) {

    /* check whether number or string */
    if (lua_isnumber(L,op)) {
      
      /* number, so check if integer or real (double) */
      if (luaL_checknumber(L,op)) {
	 /* print real : */
	  fprintf(state->f, "%f", (RtFloat)lua_tonumber(L,op));

      } else {
	
	/* print integer : */
	fprintf(state->f,"%d", (RtInt)luaL_checkinteger(L,op));
	
       }
    } else if (lua_isstring(L,op)) { 
      
      /* print string */
      fprintf(state->f, "%s", (RtToken)luaL_checkstring(L,op));
    }

    fprintf(state->f," ");
  }      

  if (tail)    
    fprintf(state->f,"%s", tail);
  

  fprintf(state->f,"\n");

}

void_t 
print_name( lua_State *L, string_t name ) {

  state_t * state = grtri_tostate(L,1);

  fprintf(state->f,"%s ", name);
}

void_t 
pretty_tab_increase( lua_State *L ) {

  state_t * state = grtri_tostate(L,1);

  state->not++;
}

void_t 
pretty_tab_descrease( lua_State *L ) {

  state_t * state = grtri_tostate(L,1);

  state->not--;
}
