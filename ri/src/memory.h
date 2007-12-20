

#ifndef grt_ri_memory_h
#define grt_ri_memory_h 1

#include <stdlib.h>
#include <malloc.h>

namespace grt
{
 
      
      inline void *
	alloc_aligned( unsigned int size )
	{

#ifndef L1_CACHE_LINE_SIZE
#define L1_CACHE_LINE_SIZE 64
#endif
	  
	  return memalign(L1_CACHE_LINE_SIZE, size);
	}

    
      
}

#endif
