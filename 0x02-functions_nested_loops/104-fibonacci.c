#include <stdio.h>

/**
 * main - Function to prints the first 98 Fibonacci numbers
 *
 *
 * Return: 0
 */

int main(void)
{
	unsigned long int a;
	unsigned long int b = 1000000000;
	unsigned long int beff = 1;
	unsigned long int aftt = 2;
	unsigned long int aftt1;
	unsigned long int aftt2;
	unsigned long int beff1;
	unsigned long int beff2;

	printf("%lu", beff);

	for (a = 1; a < 91; a++)
	{
		printf(", %lu", aftt);
		aftt += beff;
		beff = aftt - beff;
	}

	beff1 = (beff / b);
	beff2 = (beff % b);
	aftt1 = (aftt / b);
	aftt2 = (aftt % b);

	for (a = 92; a < 99; ++a)
	{
		printf(", %lu", aftt1 + (aftt2 / b));
		printf("%lu", aftt2 % b);
		aftt1 = aftt1 + beff1;
		beff1 = aftt1 - beff1;
		aftt2 = aftt2 + beff2;
		beff2 = aftt2 - beff2;
	}
	printf("\n");
	return (0);
}
