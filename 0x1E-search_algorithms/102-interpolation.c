#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array
 * using Interpolation search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: Index of value if found, otherwise -1.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t mid;

	if (array == NULL)
		return (-1);

	while (high >= low)
	{
		mid = low + (((double)(high - low) / (array[high] -
						array[low])) * (value - array[low]));

		if (mid < size)
			printf("Value checked array[%ld] = [%d]\n", mid,
					array[mid]);
		else
		{
			printf("Value checked array[%ld] is out of range\n",
					mid);
			break;
		}

		if (array[mid] == value)
			return (mid);
		if (array[mid] > value)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return (-1);
}
