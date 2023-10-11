#include "function_pointers.h"

/**
 * array_iterator - Function to iterate elements of an array for executions
 * @array: The array to iterate
 * @size: The size of the array
 * @action: A pointer to the function to be used for the execution
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int index;

	if (array == NULL || action == NULL)
		return;
	for (index = 0; index < size; index++)
		action(array[index]);
}
