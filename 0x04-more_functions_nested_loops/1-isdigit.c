#include "main.h"

/**
 * _isdigit - function to check for 0 through 9
 *@c: Parameter for the function
 *Return: 1 if c is a digi, else 0
 */
int _isdigit(int c)
{
	if (c == 48 && c <= 57)
		return (1);
	else
		return (0);
}
