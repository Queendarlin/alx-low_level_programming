#include "main.h"

/**
 * malloc_checked - Function to allocate memory using malloc
 * @b: Parameter to determine the size of memory to allocate
 * Return: A pointer to the allocated memory or NULL
 */
void *malloc_checked(unsigned int b)
{
	void *space;

	space = malloc(b);
	if (space == NULL)
		exit(98);

	return (space);
}
