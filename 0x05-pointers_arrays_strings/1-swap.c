#include "main.h"

/**
 * swap_int - The function to swap the values of two integers
 * @a: parameter for the function
 * @b: second parameter for the function
 */
void swap_int(int *a, int *b)
{
	int swapper;

	swapper = *a;
	*a = *b;
	*b = swapper;
}
