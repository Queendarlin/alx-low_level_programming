#include "main.h"

/**
 * str_concat - Function to concatenate two string
 *@s1: First string to concatenate
 *@s2: Second string to concatenate
 *Return: pointer to the content of s1 and s2 or NULL
 */
char *str_concat(char *s1, char *s2)
{
	int s1length = 0;
	int s2length = 0;
	char *conc;
	int index;

	if (s1 == NULL)
		return ("");
	if (s2 == NULL)
		return ("");
	for (index = 0; s1[index] != '\0'; index++)
		s1length++;
	for (index = 0; s2[index] != '\0'; index++)
		s2length++;
	conc = malloc(sizeof(char) * (s1length + s2length) + 1);
	if (conc == NULL)
		return (NULL);
	for (index = 0; s1[index] != '\0'; index++)
		conc[index] = s1[index];
	for (index = 0; s2[index] != '\0'; index++)
		conc[s1length + index] = s2[index];
	return (conc);
}
