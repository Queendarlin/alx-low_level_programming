#include "main.h"

/**
 * _memcpy - Function to copy 'n' bytes from memory area src to dest
 * @dest: Pointer to the destination memory area to copy data
 * @src: Pointer to the source memory area to copy data from
 * @n: Number of bytes to copy from src to dest
 *
 * Return: Returns a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int index = 0;

	while (index < n)
	{
		dest[index] = src[index];
		index++;
	}
	return (dest);
}
