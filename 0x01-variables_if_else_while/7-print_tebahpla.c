#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
	char b;

	for (b = 'z'; b >= 'a'; b--)
		putchar(b);
	putchar('\n');
	return (0);
}
