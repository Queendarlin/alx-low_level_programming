#include "main.h"

/**
 * *_strncpy - Function to copy a string
 * @dest: String to receive the copied string
 * @src: String to be copied
 * @n: number of bytes
 * Return: Return the value of dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int index;

	for (index = 0; index < n && src[index] != '\0'; index++)
	{
		dest[index] = src[index];
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}
