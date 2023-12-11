#include "main.h"

/**
 * *_strncat - Function to concatenate two strings
 * @dest: The string receiving copied string
 * @src: The string that will be copied
 * @n: the number of bytes
 * Return: Returns the value of dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int length_dest = 0;
	int index;

	for (index = 0; dest[length_dest] != '\0'; index++)
		length_dest++;
	for (index = 0; index < n && src[index] != '\0'; index++)
	{
		dest[length_dest + index] = src[index];
	}
	dest[length_dest + index] = '\0';
	return (dest);
}
