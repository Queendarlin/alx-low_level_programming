#include "main.h"

/**
 * string_toupper - Function to change all lowercase in a string to uppercase
 * @str: The string to be changed
 * Return: Pointer to the string changed
 */
char *string_toupper(char *str)
{
	int index;

	for (index = 0; str[index] != '\0'; index++)
		if (str[index] >= 'a' && str[index] <= 'z')
		{
			str[index] = str[index] - ('a' - 'A');
		}
	return (str);
}
