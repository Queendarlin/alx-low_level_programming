#include "main.h"

/**
 * more_numbers - Function that prints 0 to 14 followed by a new line
 */
void more_numbers(void)
{
	int numb;
	int two_numb;

	for (numb = 0; numb <= 10; numb++)
	{
		for (two_numb = 0; two_numb <= 14; two_numb++)
		{
			if (two_numb > 9)
			_putchar(two_numb / 10 + '0');
			_putchar(two_numb % 10 + '0');
		}
	_putchar('\n');
	}
}
