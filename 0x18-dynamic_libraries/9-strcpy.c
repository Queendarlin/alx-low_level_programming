#include "main.h"

/**
 * *_strcpy - Function to copy the string pointed to by src, including (\0)
 * @dest: pointer to dest
 * @src: pointer to src
 * Return: Returns the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int index;

	for (index = 0; src[index] != '\0'; index++)
		dest[index] = src[index];
	dest[index] = '\0';
	return (dest);
}
