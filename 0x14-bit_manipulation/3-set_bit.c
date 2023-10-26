#include "main.h"

/**
 * set_bit - Function to set the value of a bit to 1 at a given index
 * @n: The number to set to 1
 * @index: The index to evaluate
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask_set;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	mask_set = 1UL << index;
	*n = (*n | mask_set);
	return (1);
}
