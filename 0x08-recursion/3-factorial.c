#include "main.h"

/**
 * factorial - Function to print the factorial of a number
 * @n: Parameter for the function to represent the number
 * Return: Returns -1 when n < 0, 1 if equal, else the factorial
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 1)
		return (1);
	return (n * factorial(n - 1));
}
