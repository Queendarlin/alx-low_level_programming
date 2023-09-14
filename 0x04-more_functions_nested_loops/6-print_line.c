#include "main.h"

/**
 * print_line - A function to draw a straight line
 * @n: parameter for the function
 */
void print_line(int n)
{

	if (n <= 0)
		_putchar ('\n');
	else
	{
		int line;

		for (line = 0; line <= n; line++)
			_putchar('_');
		_putchar('\n');
	}
}
