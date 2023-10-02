#include <stdio.h>

/**
 * main - Function to print a program's name
 * @argc: parameter to count argument
 * @argv: parameter to store arguments
 * Return: Return 0 if more than 2 arguments, 0 on success
 */
int main(int argc, char *argv[])
{
	int num1 = 0;
	int num2 = 0;
	int result = 0;
	int count1, count2;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	for (count1 = 0; argv[1][count1] != '\0'; count1++)
		num1 = num1 * 10 + (argv[1][count1] - '0');
	for (count2 = 0; argv[2][count2] != '\0'; count2++)
		num2 = num2 * 10 + (argv[2][count2] - '0');

	while (num2 > 0)
	{
		result += num1;
		num2--;
	}
	printf("%d\n", result);

	return (0);
}
