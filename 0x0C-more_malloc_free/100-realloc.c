#include "main.h"

/**
 * _realloc - Function to reallocate memory block
 * @ptr: Pointer to the old memory
 * @old_size: The size in bytes of the space allocated to ptr
 * @new_size: The new size in bytes to allocate 
 * Return: A pointer to the newly allocated space
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int index;

	if (new_size > old_size)

