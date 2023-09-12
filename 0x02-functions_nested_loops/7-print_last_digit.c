#include "main.h"

/**
 * print_last_digit - Function to print the last digit of a number
 *
 * @a: Parameter of function
 *
 * Return: 0
 */
int print_last_digit(int a)
{
	int b;

	b = a % 10;
	if (a < 0)
		b = -b;
	_putchar(b + '0');
	return (b);
}
