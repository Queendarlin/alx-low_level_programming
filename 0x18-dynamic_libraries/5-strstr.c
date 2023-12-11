#include "main.h"

/**
 * _strstr - Function to locate a substring within a string
 * @haystack: The string to search in for the substring
 * @needle: The substring to locate
 *
 * Return: Pointer to the start of the located substring in haystack, else NULL
 */
char *_strstr(char *haystack, char *needle)
{
	char *h, *n;

	while (*haystack)
	{
		h = haystack;
		n = needle;

		while (*n && (*h == *n))
		{
			h++;
			n++;
		}

		if (*n == '\0')
		{
			return (haystack);
		}

		haystack++;
	}

	return (NULL);
}
