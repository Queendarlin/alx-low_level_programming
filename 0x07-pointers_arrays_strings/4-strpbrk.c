#include "main.h"

/**
 * _strpbrk - Function to Search a string for any of a set of bytes
 * @s: The string to search
 * @accept: Contains the characters to search for in s
 *
 * Return: Pointer to the matching byte in s seen in accept, else NULL
 */
char *_strpbrk(char *s, char *accept)
{
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
			{
				return (s);
			}
		}
		s++;
	}

	return (NULL);
}
