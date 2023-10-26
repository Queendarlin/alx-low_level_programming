#include "main.h"

/**
 * get_endianness - Function to check the endianness
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int byte_num = 1;
	char *byte_ptr = (char *)&byte_num;

	if (*byte_ptr == 1)
		return (1);
	else
		return (0);
}
