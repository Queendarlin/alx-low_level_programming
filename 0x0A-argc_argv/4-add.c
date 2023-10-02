#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: pointer to array of arguments stored
 *
 * Return: Returns 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int sum = 0;
	int index1, index2, value;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (index1 = 1; index1 < argc; index1++)
	{
		char *arg = argv[index1];

		for (index2 = 0; arg[index2] != '\0'; index2++)
		{
			if (arg[index2] < '0' || arg[index2] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}
		value = atoi(arg);

		if (value > 0)
		{
			sum += value;
		}
	}

	printf("%d\n", sum);
	return (0);
}
