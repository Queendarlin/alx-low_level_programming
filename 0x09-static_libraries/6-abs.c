#include "main.h"

/**
 * _abs - The function that computes the absolute value of an integer
 *
 * @b: parameter for the function
 *
 * Return: 0
 */
int _abs(int b)
{
	if (b < 0)
		return (-b);
	else if (b >= 0)
		return (b);
	return (0);
}
