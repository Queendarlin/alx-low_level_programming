#include "function_pointers.h"

/**
 * print_name - Function to print a name
 * @name: The name to be printed
 * @f: The function pointer to print_name
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
