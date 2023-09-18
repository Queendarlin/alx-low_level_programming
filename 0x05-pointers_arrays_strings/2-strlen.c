#include "main.h"

/**
 * _strlen - Function to return the length of a string
 * @s: parameter for the function
 * Return: Returns the length of the string
 */
int _strlen(char *s)
{
	int string_length = 0;

	while (s[string_length] != '\0')
		string_length++;
	return (string_length);
}
