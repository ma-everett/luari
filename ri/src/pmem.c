

/* grt : ri : pmem.c */

#include "pmem.h"


pointer_t
grtri_alloc( pointer_t ptr, uint_t nsize ) {

  if (nsize == 0) {

    free(ptr);
    return NULL;
  }

  return realloc(ptr,nsize);
}
