#include "main.h"

/**
 * binary_to_uint - Function to convert binary number to an unsigned int
 * @b: Pointer to a string of 0 and 1 characters
 * Return: The converted number, or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int bin_result = 0;
	unsigned int index = 0;

	if (b == NULL)
		return (0);

	while (b[index] != '\0')
	{
		if (b[index] == '0')
			bin_result <<= 1;
		else if (b[index] == '1')
			bin_result = (bin_result << 1) | 1;
		else
			return (0);
		index++;
	}
	return (bin_result);
}
