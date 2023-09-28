#include "main.h"

/**
 * _strlen_recursion - Function to return the length of a string
 * @s: Pointer to the length of the string
 * Return: Returns the length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s != '\0')
	{
		return (1 + _strlen_recursion(s + 1));
	}
	return (0);
}
