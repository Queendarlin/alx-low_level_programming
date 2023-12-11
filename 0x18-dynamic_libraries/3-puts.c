#include "main.h"

/**
 * _puts - function to print a string, followed by a new line, to stdout
 * @str: pointer to the string
 */
void _puts(char *s)
{
	int index;

	for (index = 0; s[index] != '\0'; index++)
		_putchar(s[index]);
	_putchar('\n');
}
