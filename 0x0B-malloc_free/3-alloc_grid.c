#include "main.h"

/**
 * alloc_grid - Function for a 2D array of integers memory allocation
 * @width: The number of grid columns
 * @height: The number of grid rows
 * Return: A pointer to the 2D array or NULL
 */
int **alloc_grid(int width, int height)
{
	int index1;
	int index2;
	int **grid2D;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	grid2D = malloc(sizeof(int *) * height);

	if (grid2D == NULL)
	{
		return (NULL);
	}

	for (index1 = 0; index1 < height; index1++)
	{
		grid2D[index1] = malloc(sizeof(int) * width);

		if (grid2D[index1] == NULL)
		{
			for (index2 = 0; index2 < index1; index2++)
			{
				free(grid2D[index2]);
			}
			free(grid2D);
			return (NULL);
		}

		for (index2 = 0; index2 < width; index2++)
		{
			grid2D[index1][index2] = 0;
		}
	}

	return (grid2D);
}
