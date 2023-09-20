#include "main.h"

/**
 * _strcmp - Function to compare two strings
 * @s1: The first string to compare
 * @s2: The second string to compare
 * Return: Returns zero, less than or greater than zero
 */
int _strcmp(char *s1, char *s2)
{
	int index;

	for (index = 0; s1[index] != '\0' || s2[index] != '\0'; index++)
	{
		if (s1[index] != s2[index])
		{
			return (s1[index] - s2[index]);
		}
	}
	return (0);
}
