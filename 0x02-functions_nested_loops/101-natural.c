#include "main.h"
#include <stdio.h>
/**
 * main - Function to sum of all the multiples of 3 or 5 below 1024
 *
 * Return: 0
 */
int main(void)
{
	int sum_3_5 = 0;
	int c;

	for (c = 0; c < 1024; c++)
	{
		if (c % 3 == 0 || c % 5 == 0)
		sum_3_5 = sum_3_5 + c;
	}
	printf("%d\n", sum_3_5);
	return (0);
}
