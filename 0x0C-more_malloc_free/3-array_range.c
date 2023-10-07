#include "main.h"

/**
 * array_range - Function to create range of arrays
 * @min: The minimum value of the array
 * @max: The maximum value of the array
 * Return: A pointer to the newly created array or NULL
 */
int *array_range(int min, int max)
{
	int index;
	int *range;

	if (min > max)
		return (NULL);
	range = malloc(sizeof(int) * max - min + 1);
	if (range == NULL)
		return (NULL);
	for (index = 0; index <= max - min; index++)
		range[index] = min + index;
	return (range);
}
