#include "main.h"

/**
 * _sqrt_supporter - Function to do the calculation
 *
 * @n: Number to estimate the square root
 * @estimates: The current estimates for the square root
 * Return: -1, if n shows no natural square root or the square root of n
 */
int _sqrt_supporter(int n, int estimates)
{
	if (n < 0)
		return (-1);
	if (estimates * estimates == n)
		return (estimates);
	if (estimates * estimates > n)
		return (-1);
	return (_sqrt_supporter(n, estimates + 1));
}

/**
 *  _sqrt_recursion - Function to return the natural square root of a number
 * @n: Number to estimate the square root
 * Return: the square root of n
 */
int _sqrt_recursion(int n)
{
	return (_sqrt_supporter(n, 1));
}
