#include "main.h"

/**
 * _calloc - Function to allocates memory for an array
 * @size: size of the array
 * @nmemb: Number of array elements
 * Return: Returns a pointer to the allocated memory or NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int *arr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	arr = calloc(nmemb, size);
	if (arr == NULL)
		return (NULL);
	else
		return (arr);
}
