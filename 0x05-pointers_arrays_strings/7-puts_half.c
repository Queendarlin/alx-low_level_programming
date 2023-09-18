#include "main.h"

/**
 * puts_half - Function to print half of a string
 * @str: Pointer to the half of a string
 */
void puts_half(char *str)
{
	int index;
	int n;
	int length = 0;

	for (index = 0; str[index] != '\0'; index++)
		length++;
	{
		n = (length - 1) / 2;
		for (index = n + 1; str[index] != '\0'; index++)
			_putchar(str[index]);
	}
	_putchar('\n');
}
