#include "main.h"

/**
 * reverse_array - Function to reverse the content of an array of integers
 * @a: Pointer to the array
 * @n: Number of elements in the array
 */
void reverse_array(int *a, int n)
{
	int start_index = 0;
	int end_index = n - 1;
	int holder;

	while (start_index < end_index)
	{
		holder = a[start_index];
		a[start_index] = a[end_index];
		a[end_index] = holder;

		start_index++;
		end_index--;
	}
}

