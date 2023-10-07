#include "main.h"

/**
 * string_nconcat - Function to concatenate two strings and allocate memory
 * @s1: First string to concatenate
 * @s2: Second string to concatenate
 * Return: A pointer to the concatenated string or NULL
 * @n: Number of bytes to concatenate from s2
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int s1length = 0;
	unsigned int s2length = 0;
	char *conc;
	unsigned int index;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (index = 0; s1[index] != '\0'; index++)
		s1length++;
	for (index = 0; s2[index] != '\0'; index++)
		s2length++;
	if (n >= s2length)
		n = s2length;
	conc = malloc(sizeof(char) * (s1length + n) + 1);
	if (conc == NULL)
		return (NULL);
	for (index = 0; index < s1length; index++)
		conc[index] = s1[index];
	for (index = 0; index < s2length; index++)
		conc[s1length + index] = s2[index];
	conc[s1length + n] = '\0';

	return (conc);
}
