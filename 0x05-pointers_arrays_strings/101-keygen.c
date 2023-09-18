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
	int index, num, diff;

	num = 0;
	srand(time(NULL));

	for (index = 0; index < 100; index++)
	{
		password[index] = rand() % 78;
		num += (password[index] + '0');
		putchar(password[index] + '0');
		if ((2772 - num) - '0' < 78)
		{
			diff = 2772 - num - '0';
			num += diff;
			putchar(diff + '0');
			break;
		}
	}
	return (0);
}
