

/* grt : ri : pmem.h */

#ifndef grtri_pmem_h
#define grtri_pmem_h 1

#include "typedefs.h"
#include <stdlib.h>

pointer_t grtri_alloc( pointer_t ptr, uint_t nsize );

#define grtri_malloc( s ) grtri_alloc( NULL, (s) )
#define grtri_free( p ) grtri_alloc( (p), NIL )

#endif /* grtri_pmem_h */
