#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 * using Jump search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: (int) The index where value is located,
 * or (-1) if not found or if array is NULL.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, jump, jump_step;

	if (array == NULL || size == 0)
		return (-1);

	jump_step = sqrt(size);
	for (i = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		i = jump;
		jump += jump_step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, jump);

	jump = jump < size - 1 ? jump : size - 1;
	for (; i < jump && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
