#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: pointer to array of arguments stored
 *
 * Return: Returns 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int cents;
	int coins[] = {25, 10, 5, 2, 1};
	int coins_num = sizeof(coins) / sizeof(coins[0]);
	int count = 0;
	int index = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	while (cents > 0 && index < coins_num)
	{
		if (cents >= coins[index])
		{
			int num_of_coins = cents / coins[index];

			count += num_of_coins;
			cents %= coins[index];
		}
		index++;
	}

	printf("%d\n", count);

	return (0);
}
