#include "main.h"

/**
 * _print_rev_recursion - Function to print a string in reverse
 * @s: Pointer to the string to be reversed
 */
void _print_rev_recursion(char *s)
{
	if (*s != '\0')
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
