#include "main.h"

/**
 * print_numbers - A function that prints 0 to 9
 */
void print_numbers(void)
{
	int numb;

	for (numb = 0; numb <= 9; numb++)
		_putchar(numb + '0');
	_putchar('\n');
}
