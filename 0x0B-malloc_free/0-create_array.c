#include "main.h"

/**
 * create_array - Function to create an array of characters
 * @size: The size of the array
 * @c: The specific character to store in the array
 * Return: Returns a pointer to the array or NULL
 * char *create_array(unsigned int size, char c)
 */
char *create_array(unsigned int size, char c)
{
	char *arry;
	unsigned int index;

	if (size == 0)
		return (NULL);
	arry = malloc(sizeof(char) * size);
	if (arry == NULL)
		return (NULL);
	for (index = 0; index < size; index++)
		arry[index] = c;
	return (arry);
}
