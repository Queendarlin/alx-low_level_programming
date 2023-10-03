#include "main.h"

/**
 * _strdup - Function for a copied string newly allocated space in memory
 * @str: Pointer to the string to copy
 * Return: Returns a pointer to the duplicated string or NULL
 */
char *_strdup(char *str)
{
	char *cpy;
	int index;
	int length;

	if (str == NULL)
		return (NULL);
	for (index = 0; str[index] != '\0'; index++)
		length++;
	cpy = malloc(sizeof(char) * length + 1);
	if (cpy == NULL)
		return (NULL);
	for (index = 0; str[index] != '\0'; index++)
		cpy[index] = str[index];
	return (cpy);
}
