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

	if (min > max)
		return (NULL);
	values = malloc(sizeof(int) * max - min + 1);
	if (values == NULL)
		return (NULL);
	for (index = 0; min <= max; index++)
		values[index] = min++;
	return (values);
}
