#include "main.h"

/**
 * array_range - Function to create range of arrays
 * @min: The minimum value of the array
 * @max: The maximum value of the array
 * Return: A pointer to the newly created array or NULL
 */
int *array_range(int min, int max)
{
	int *values;
	int index;
	int size;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	values = malloc(sizeof(int) * size);
	if (values == NULL)
		return (NULL);

	for (index = 0; min <= max; index++)
		values[index] = min++;
	return (values);
}

