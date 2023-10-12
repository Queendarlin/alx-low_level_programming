#include "variadic_functions.h"

/**
 * sum_them_all - Function that returns the sum of all its parameters
 * @n: The number of arguments
 * Return: The summ of all parameters or 0
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int index;
	unsigned int sum_all = 0;
	va_list sum_arg;

	if (n == 0)
		return (0);

	va_start(sum_arg, n);

	for (index = 0; index < n; index++)
	{
		sum_all = sum_all + va_arg(sum_arg, unsigned int);
	}
	va_end(sum_arg);
	return (sum_all);
}
