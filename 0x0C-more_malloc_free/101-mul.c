#include "main.h"

/**
 * _positive_int - Function to check if a string consists of only digits
 * @string: The string to check
 * Return: 1 if it's a positive integer, 0 otherwise
 */
int _positive_int(char *string)
{
	if (string == NULL || *string == '\0')
		return (0);

	while (*string)
	{
		if (*string < '0' || *string > '9')
			return (0);
		string++;
	}

	return (1);
}

/**
 * main - Function to multiply two positive numbers
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 on success, or 98 on error.
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc != 3 || !_positive_int(argv[1]) || !_positive_int(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	result = num1 * num2;

	printf("%d\n", result);

	return (0);
}
