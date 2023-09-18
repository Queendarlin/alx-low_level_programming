#include "main.h"
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point for the Program to generate random valid passwords
 *
 * Return: 0 on success
 */
int main(void)
{
	int password[100];
	int index, sum, diff;

	sum = 0;

	srand(time(NULL));

	for (index = 0; index < 100; index++)
	{
		password[index] = rand() % 78;
		sum += password[index];
		putchar(' ' + password[index]);
		if ((2772 - sum) < 78)
		{
			diff = 2772 - sum;
			sum += diff;
			putchar(' ' + diff);
			break;
		}
	}

	putchar('\n');

	return (0);
}
