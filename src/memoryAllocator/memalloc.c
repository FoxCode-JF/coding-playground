// Simple malloc
#include "memalloc.h"
#include <stdio.h>
#include <stdlib.h>

void * memalloc(size_t size)
{
	void *block;
	block = sbrk(size);
	if (block == (void*) -1)
	{
		return NULL;
	}

	return block;
}