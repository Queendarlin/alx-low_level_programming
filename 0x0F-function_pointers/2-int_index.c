#include "function_pointers.h"

/**
 * int_index - Function to search for an integer
 * @array: The array to search for the integer in
 * @size: The number of elements in the array
 * @cmp: A pointer to the function to be used to compare values
 * Return: Index of the first element for which the cmp does not return 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int index;

	if (array == 0 || cmp == 0)
		return (-1);
	if (size <= 0)
		return (-1);
	for (index = 0; index < size; index++)
	{
		if (cmp(array[index]) == 1)
			return (index);
	}
	return (-1);
}
