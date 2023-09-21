#include "main.h"

/**
 * leet - Function to encode a string into 1337.
 * @str: The encoded string
 *
 * Return: A pointer to str
 */
char *leet(char *str)
{
	int index;
	char leet_replaced[] = "aAeEoOtTlL";
	char leet_new[] = "4433007711";

	for (index = 0; str[index] != '\0'; index++)
	{
		int inner_index;

		for (inner_index = 0; leet_replaced[inner_index] != '\0'; inner_index++)
		{
			if (str[index] == leet_replaced[inner_index])
			{
				str[index] = leet_new[inner_index];
				break;
			}
		}
	}

	return (str);
}
