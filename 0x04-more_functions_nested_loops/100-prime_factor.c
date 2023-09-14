#include <stdio.h>
#include <math.h>

/**
 * main - function to find and print the largest prime factor of 612852475143
 * Return: returns 0 on Success
 */
int main(void)
{
	long int numb;
	long int largest;
	long int a;

	numb = 612852475143;
	largest = -1;

	while (numb % 2 == 0)
	{
		largest = 2;
		numb /= 2;
	}

	for (a = 3; a <= sqrt(numb); a = a + 2)
	{
		while (numb % a == 0)
		{
			largest = a;
			numb = numb / a;
		}
	}

	if (numb > 2)
		largest = numb;

	printf("%ld\n", largest);

	return (0);
}
