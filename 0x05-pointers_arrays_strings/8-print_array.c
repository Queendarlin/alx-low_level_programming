#include "main.h"

/**
 * print_array - Function to print n elements of an array of integers
 * @a: pointer to the n element
 * @n: the number of elements for the array
 */
void print_array(int *a, int n)
{
	int c;

	for (c = 0; c < n; c++)
	{
		printf("%d", a[c]);
		if (c < n - 1)
			printf(", ");
	}
	printf("\n");
}
