#include "main.h"

/**
 * _strchr - Function to locate a character of interest in a string
 * @s: The string to search for the character
 * @c: The character to be found
 *
 * Return: A pointer to the first occurrence of c in s, else NULL if not found
 */
char *_strchr(char *s, char c)
{
	int index = 0;

	while (s[index] >= '\0')
	{
		if (s[index] == c)
			return (&s[index]);
		index++;
	}
	return (0);
}
