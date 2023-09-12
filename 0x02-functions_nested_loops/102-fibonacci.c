#include <stdio.h>

/**
 * main - The entry point of the program
 *
 * Return: 0
 */
int main(void)
{
	unsigned long int first_count = 1;
	unsigned long int second_count = 2;
	unsigned long int next_count;
	int c;

	printf("%lu, ", first_count);
	for (c = 1; c < 50; c++)
	{
		printf("%lu", second_count);
		next_count = first_count + second_count;
		first_count = second_count;
		second_count = next_count;
		if (c != 49)
			printf(", ");
	}
	printf("\n");
	return (0);
}
