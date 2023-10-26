#include "main.h"

/**
 * clear_bit - Function to clear a bit
 * @n: The number of the bit
 * @index: The index to evaluate
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask_clear;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	mask_clear = 1UL << index;
	*n = (*n & (~mask_clear));
	return (1);
}
