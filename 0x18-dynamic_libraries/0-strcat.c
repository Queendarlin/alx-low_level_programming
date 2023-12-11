#include "main.h"

/**
 * *_strcat - Function to concatenate two strings
 * @dest: the string that will receive the appendage
 * @src: The string to be appended
 * Return: Returns the value of the concatenate
 */
char *_strcat(char *dest, char *src)
{
	int length_dest = 0;
	int length_src = 0;
	int index;

	for (index = 0; dest[index] != '\0'; index++)
		length_dest++;
	for (index = 0; src[index] != '\0'; index++)
		length_src++;
	for (index = 0; index < length_src; index++)
	{
		dest[length_dest + index] = src[index];
	}
	dest[length_dest + length_src] = '\0';
	return (dest);
}
