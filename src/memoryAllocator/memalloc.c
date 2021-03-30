// Simple malloc based on https://arjunsreedharan.org/post/148675821737/write-a-simple-memory-allocator

#include "memalloc.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <vcruntime.h>

header_t *head, *tail;

pthread_mutex_t global_malloc_lock;

void *memalloc(size_t size)
{
	size_t total_size;
	void *block;
	header_t *header = NULL;

	if (size == 0)
	{
		return NULL;
	}

	pthread_mutex_lock(&global_malloc_lock);
	header = get_free_block(size);

	if (header != NULL)
	{
		header->s.is_free = false;
		pthread_mutex_unlock(&global_malloc_lock);
		return (void*)(header + 1);					// + 1 shifts pointer to the byte right after the header
	}

	total_size = sizeof(header_t) + size;
	block = sbrk(total_size);

	if (block == (void*) -   1)
	{
		pthread_mutex_unlock(&global_malloc_lock);
		return NULL;
	}

	header = block;
	header->s.size = size;
	header->s.is_free = false;
	header->s.next = NULL;

	if (head == NULL)
	{
		head = header;
	}
	if (tail != NULL)
	{
		tail->s.next = header;
	}

	tail = header;
	pthread_mutex_unlock(&global_malloc_lock);
	return (void*)(header + 1);
}


void memfree(void *block)
{
	
}

/**
 * @brief      Gets the free block using first fit strategy
 *
 * @param[in]  size  The size of requested block in bytes
 *
 * @return     pointer to the free block of memory
 */
static header_t *get_free_block(size_t size)
{
	header_t *curr = head;
	while (curr) 
	{
		if (curr->s.is_free && curr->s.size >= size)
		{
			return curr;
		}	
		curr = curr->s.next;
	}
	return NULL;
}