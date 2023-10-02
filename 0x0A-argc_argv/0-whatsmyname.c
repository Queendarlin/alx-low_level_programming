#include <stdio.h>

/**
 * main - Function to print a program's name
 * @argc: parameter to count argument
 * @argv: parameter to store arguments
 * Return: Return 0 on success
 */
int main(int argc, char *argv[])
{
	(void) argc;
	printf("%s\n", argv[0]);
	return (0);
}
