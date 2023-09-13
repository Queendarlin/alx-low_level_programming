#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: 0
 */
int main(void)
{
	int limit_count = 4000000;
	int first_count = 1;
	int second_count = 2;
	int next_count;
	int sum_count = 2;

	while (next_count <= limit_count)
	{
		next_count = first_count + second_count;
		if (next_count % 2 ==  0)
			sum_count = sum_count + next_count;
		first_count = second_count;
		second_count = next_count;
	}
	printf("%d\n", sum_count);
	return (0);
}
