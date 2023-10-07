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
	char *new_ptr;
	unsigned int index;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);

	if (new_size < old_size)
	{
		for (index = 0; index < new_size; index++)
			new_ptr[index] = ((char *)ptr)[index];
	}

	if (new_size > old_size)
	{
		for (index = 0; index < old_size; index++)
			new_ptr[index] = ((char *)ptr)[index];
	}

	free(ptr);
	return (new_ptr);
}
