#include "main.h"

#define ERR_MSG "Error"

/**
 * is_digit - Function to check if a string has only digit characters
 * @string: The string to be checked
 * Return: 1 if the string contains only digits, else 0
 */
int is_digit(char *string)
{
	int index = 0;

	while (string[index])
	{
		if (string[index] < '0' || string[index] > '9')
			return (0);
		index++;
	}
	return (1);
}

/**
 * _strlen - Function to compute the length of a string
 * @string: The string to compute
 *
 * Return: Length of string
 */
int _strlen(char *string)
{
	int index = 0;

	while (string[index] != '\0')
	{
		index++;
	}
	return (index);
}

/**
 * errors - Function to handle errors for the main function
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - Function to Multiply two positive numbers
 * @argc: The number of command-line arguments
 * @argv: The Array of command-line arguments
 * Return: Always returns 0 (Success).
 */
int main(int argc, char *argv[])
{
	char *string1, *string2;
	int len1, len2, result_len, index, hold, num1, num2, *result, zero = 0;

	string1 = argv[1], string2 = argv[2];
	if (argc != 3 || !is_digit(string1) || !is_digit(string2))
		errors();
	len1 = _strlen(string1);
	len2 = _strlen(string2);
	result_len = len1 + len2 + 1;
	result = malloc(sizeof(int) * result_len);
	if (!result)
		return (1);
	for (index = 0; index <= len1 + len2; index++)
		result[index] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		num1 = string1[len1] - '0';
		hold = 0;
		for (len2 = _strlen(string2) - 1; len2 >= 0; len2--)
		{
			num2 = string2[len2] - '0';
			hold += result[len1 + len2 + 1] + (num1 * num2);
			result[len1 + len2 + 1] = hold % 10;
			hold /= 10;
		}
		if (hold > 0)
			result[len1 + len2 + 1] += hold;
	}
	for (index = 0; index < result_len - 1; index++)
	{
		if (result[index])
			zero = 1;
		if (zero)
			_putchar(result[index] + '0');
	}
	if (!zero)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
