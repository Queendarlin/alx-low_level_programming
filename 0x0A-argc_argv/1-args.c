#include <stdio.h>

/**
 * main - Function to print a program's name
 * @argc: parameter to count argument
 * @argv: parameter to store arguments
 * Return: Return 0 on success
 */
int main(int argc, char *argv[])
{
	(void) argv;
	printf("%d\n", argc - 1);
	return (0);
}
