#include "main.h"

/**
 * print_diagonal - function to draw diagonal lines
 * @n: parameter for the function
 */
void print_diagonal(int n)
{
	if (n <= 0)
		_putchar('\n');
	else
	{
		int spaces, lines;

		for (spaces = 1; spaces <= n; spaces++)
		{
			for (lines = 1; lines <= spaces; lines++)
				_putchar(' ');
			_putchar('\\');
			_putchar('\n');
		}
	}
}
