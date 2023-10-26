#include "main.h"

/**
 * print_binary - Function to print the binary representation of a number
 * @n: The number to print
 * Return: The printed binary
 */
void print_binary(unsigned long int n)
{
	unsigned int bit_set = 0;
	unsigned int index;

	if (n == 0)
	{
		_putchar('0');
		return;
	}
	for (index = sizeof(unsigned long int) * 8 - 1;
			index < sizeof(unsigned long int) * 8; index--)
	{
		if (n & (1UL << index))
		{
			bit_set = 1;
			_putchar('1');
		}
		else if (bit_set)
			_putchar('0');
	}
}
