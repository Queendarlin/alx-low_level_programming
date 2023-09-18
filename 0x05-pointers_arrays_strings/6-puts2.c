#include "main.h"

/**
 * puts2 - Function to print every other character of a string
 * @str: pointer to every other character of the string
 */
void puts2(char *str)
{
	int index;

	for (index = 0; str[index] != '\0'; index++)
	{
		if (index % 2 == 0)
			_putchar(str[index]);
	}
	_putchar('\n');
}
