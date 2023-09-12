#include "main.h"

/**
 * _isalpha - The function to check alphabetic character
 *
 * @c: Parameter for the function
 *
 * Return: Returns  1 if c is a letter, lowercase or uppercase or otherwise 0
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
