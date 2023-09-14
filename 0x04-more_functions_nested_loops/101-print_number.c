#include "main.h"

/**
 * print_number - function to print an integer
 * @n: function parameter
 */
void print_number(int n)
{
	unsigned int b;

	if (n < 0)
	{
		b = -n;
		_putchar('-');
	} else
	{
		b = n;
	}

	if (b / 10)
	{
		print_number(b / 10);
	}

	_putchar((b % 10) + '0');
}
