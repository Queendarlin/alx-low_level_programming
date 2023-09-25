#include "main.h"

/**
 * print_diagsums - Function to print sum of two diagonals of a square matrix
 * @a: Pointer to the square matrix
 * @size: number of rows or columns showing the size of the matrix
 */
void print_diagsums(int *a, int size)
{
	int sum1 = 0;
	int sum2 = 0;
	int row, column;

	for (row = 0; row < size; row++)
	{
		for (column = 0; column < size; column++)
		{
			if (row == column)
				sum1 += a[row * size + column];
			if (row + column == size - 1)
				sum2 += a[row * size + column];
		}
	}

	printf("%d, %d\n", sum1, sum2);
}
