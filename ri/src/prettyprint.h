

#ifndef grtri_prettyprint_h
#define grtri_prettyprint_h 1

#include "typedefs.h"
#include <lua.h>

void_t pretty_tab( lua_State *L );
void_t print_args_f( lua_State *L, string_t tail );
void_t print_args( lua_State *L, string_t tail );
void_t print_name( lua_State *L, string_t name );
void_t pretty_tab_increase( lua_State *L );
void_t pretty_tab_descrease( lua_State *L );

#endif /* grtri_prettyprint_h */
