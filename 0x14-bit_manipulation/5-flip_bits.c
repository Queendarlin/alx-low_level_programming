#include "main.h"

/**
 * flip_bits - Function to flip a bit
 * @n: The number of bits to flip
 * @m: The other number to get from
 * Return: The number of flipped bit
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip = n ^ m;
	unsigned int count_bit = 0;

	while (flip > 0)
	{
		count_bit += flip & 1;
		flip >>= 1;
	}
	return (count_bit);
}
