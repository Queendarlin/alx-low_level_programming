#include <stdio.h>
#include <stdlib.h>

/**
 * main - Function to print a program's name
 * @argc: parameter to count argument
 * @argv: parameter to store arguments
 * Return: Return 0 if more than 2 arguments, 0 on success
 */
int main(int argc, char *argv[])
{

	int num1, num2, result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	result = num1 * num2;

	printf("%d\n", result);

	return (0);
}
