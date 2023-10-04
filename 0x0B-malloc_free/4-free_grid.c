#include "main.h"

/**
 * free_grid - Function to free a 2D grid created by alloc-grid
 * @grid: Pointer to the 2D grid to be freed
 * @height: The number of grid rows
 */
void free_grid(int **grid, int height)
{
	int index;

	for (index = 0; index < height; index++)
		free(grid[index]);
	free(grid);
}

