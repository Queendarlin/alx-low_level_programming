#include "main.h"

/**
 * print_rev - Function to print a string in reverse
 * @s: Pointer to the reversed string
 */
void print_rev(char *s)
{
	int index;
	int length = 0;

	for (index = 0; s[index] != 0; index++)
		length++;
	for (index = length - 1; index >= 0; index--)
		_putchar(s[index]);
	_putchar('\n');
}
