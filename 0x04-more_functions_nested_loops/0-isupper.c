#include "main.h"

/**
 * _isupper - function to check for uppercase character
 * @c: Parameter of the function
 * Return: 1 if c is uppercase else 0
 */
int _isupper(int c)
{
	if (c >= 'A' && c <=  'Z')
		return (1);
	else
		return (0);
}
