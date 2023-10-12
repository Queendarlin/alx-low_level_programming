#include "variadic_functions.h"

/**
 * print_numbers - Function to print numbers
 * @separator: The string to be printed between numbers
 * @n: Number of integers passed to the function
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int index, var_num;
	va_list hold;

	va_start(hold, n);
	for (index = 0; index < n; index++)
	{
		var_num = va_arg(hold, unsigned int);
		printf("%d", var_num);
		if (index != (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");
	va_end(hold);
}
