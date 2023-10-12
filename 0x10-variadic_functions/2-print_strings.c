#include "variadic_functions.h"

/**
 * print_strings - Function to print strings
 * @separator: The string to be printed between the strings
 * @n: The number of strings passed to the function
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int index;
	char *string;
	va_list ar_string;

	va_start(ar_string, n);
	for (index = 0; index < n; index++)
	{
		string = va_arg(ar_string, char*);
		if (string == NULL)
		{
			printf("(nul)");
		}
		else
		{
			printf("%s", string);
		}
		if (index != (n - 1) && separator != NULL)
		{
			printf("%s", separator);
		}
	}
	printf("\n");
	va_end(ar_string);
}
