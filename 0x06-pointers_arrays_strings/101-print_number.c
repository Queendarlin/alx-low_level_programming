#include "main.h"

/**
 * print_number - Function to print an integer
 * @n: Integer to be printed.
 */
void print_number(int n)
{
	unsigned int neg;

	neg = n;

	if (n < 0)
	{
		_putchar('-');
		neg = -n;
	}
	if (neg / 10 != 0)
	{
		print_number(neg / 10);
	}
	_putchar(neg % 10 + '0');
}
