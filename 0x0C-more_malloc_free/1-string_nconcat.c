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
	char *conc;
	unsigned int index1 = 0, index2 = 0, s1length = 0, s2length = 0;

	while (s1 && s1[s1length])
		s1length++;
	while (s2 && s2[s2length])
		s2length++;

	if (n < s2length)
		conc = malloc(sizeof(char) * (s1length + n + 1));
	else
		conc = malloc(sizeof(char) * (s1length + s2length + 1));

	if (!conc)
		return (NULL);

	while (index1 < s1length)
	{
		conc[index1] = s1[index1];
		index1++;
	}

	while (n < s2length && index1 < (s1length + n))
		conc[index1++] = s2[index2++];

	while (n >= s2length && index1 < (s1length + s2length))
		conc[index1++] = s2[index2++];

	conc[index1] = '\0';

	return (conc);
}
