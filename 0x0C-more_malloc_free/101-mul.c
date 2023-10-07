#include "main.h"

/**
 * error_exit - Function to print error message and exit with status 98
 */
void error_exit(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * is_positive_number - Function to check if a string is a positive number
 * @string: The string to check.
 *
 * Return: 1 if it's a positive number, 0 otherwise
 */
int is_positive_number(char *string)
{
	if (*string == '\0')
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
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Return: 0 if successful, otherwise 98 for errors.
 */
int main(int argc, char *argv[])
{
	int num1, num2;

	if (argc != 3)
		error_exit();

	if (!is_positive_number(argv[1]) || !is_positive_number(argv[2]))
		error_exit();

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	printf("%d\n", num1 * num2);

	return (0);
}
