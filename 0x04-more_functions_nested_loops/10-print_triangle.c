#include "main.h"
/**
 * print_triangle - function to print a triangle, followed by a new line
 * @size: parameter for the function
 */
void print_triangle(int size)
{
	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		int c, d;

		for (c = 1; c <= size; c++)
		{
			for (d = c; d < size; d++)
			{
				_putchar(' ');
			}

			for (d = 1; d <= c; d++)
			{
				_putchar('#');
			}

			_putchar('\n');
		}
	}
}
