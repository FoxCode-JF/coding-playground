#include <unistd.h>
#include <pthread.h>

typedef uint8_t ALIGN[16];

union header
{
	struct header_t
	{
		size_t size;
		bool is_free;
		struct header_t *next;
	} s;
	ALIGN stub;
};

typedef union header header_t;


void *memalloc(size_t size);
header_t *get_free_block(size_t size);