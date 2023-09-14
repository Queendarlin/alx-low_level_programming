#include "main.h"
#include <stdio.h>

/**
 * main - Entry point of the program
 * Return: returns 0 on success
 */
int main(void)
{
	int n;

	for (n = 1; n <= 100; n++)
	{
		if (n % 3 == 0)
			printf("%s", "Fizz");
		else if (n % 5 == 0)
			printf("%s", "Buzz");
		else if (n % 3 == 0 && n % 5 == 0)
			printf("%s", "FizzBuzz");
		else
			printf("%d", n);
		if (n != 100)
			printf(" ");
	}
	printf("\n");
	return (0);
}
