#include "main.h"

/**
 * _memset - Function to fill memory with a constant byte.
 * @s: Pointer to the memory area to be filled
 * @b: Constant byte value used to fill the memory area
 * @n: Number of bytes to be filled
 *
 * Return: Returns s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int index = 0;

	while (index < n)
	{
		s[index] = b;
		index++;
	}

	return (s);
}
