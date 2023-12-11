#include "main.h"

/**
 * _abs - The function that computes the absolute value of an integer
 *
 * @b: parameter for the function
 *
 * Return: 0
 */
int _abs(int n)
{
	if (n < 0)
		return (-n);
	else if (n >= 0)
		return (n);
	return (0);
}
