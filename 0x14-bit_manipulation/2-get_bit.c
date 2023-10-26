#include "main.h"

/**
 * get_bit - Function to return the value of a bit at a given index
 * @n: The number at the particular index
 * @index: The index to evaluate
 * Return: The value of the bit at index index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask_bit;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);
	mask_bit = 1UL << index;
	if ((n & mask_bit) == mask_bit)
		return (1);
	else
		return (0);
}
