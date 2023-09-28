#include "main.h"

/**
 * _pow_recursion - Function to return the value of x raised to power y
 * @x: Parameter for the base
 * @y: Parameter for exponent
 * Return: -1, if y is < 0, 1, if y is 0, or the result of x^y
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
