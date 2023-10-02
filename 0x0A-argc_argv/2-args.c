#include <stdio.h>

/**
 * main - Function to print a program's name
 * @argc: parameter to count argument
 * @argv: parameter to store arguments
 * Return: Return 0 on success
 */
int main(int argc, char *argv[])
{
	int index;

	for (index = 0; index < argc; index++)
		printf("%s\n", argv[index]);
	return (0);
}
