#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: A pointer to the previously allocated memory
 * @old_size: The size of the allocated space in bytes
 * @new_size: The new size in bytes
 *
 * Return: A pointer to the reallocated memory block
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	if (new_size < old_size)
		old_size = new_size;

	memcpy(new_ptr, ptr, old_size);
	free(ptr);

	return (new_ptr);
}
