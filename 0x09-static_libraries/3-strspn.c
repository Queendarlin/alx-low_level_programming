#include "main.h"

/**
 * _strspn - Function to access the length of a prefix substring
 * @s: The string to search
 * @accept: Characters acceptable in the prefix substring
 *
 * Return: Number of bytes in the initial segment of s only from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int seen;

	while (*s)
	{
		for (seen = 0; accept[seen]; seen++)
		{
			if (*s == accept[seen])
			{
				count++;
				break;
			}
			else if (accept[seen + 1] == '\0')
				return (count);
		}
		s++;
	}

	return (count);
}
