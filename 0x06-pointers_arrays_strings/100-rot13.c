#include "main.h"

/**
 * rot13 - Function to encode a string using ROT13.
 * @str: The encoded string
 *
 * Return: a pointer to str
 */
char *rot13(char *str)
{
	char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int index, inner_index;

	for (index = 0; str[index] != '\0'; index++)
	{
		for (inner_index = 0; alphabet[inner_index] != '\0'; inner_index++)
		{
			if (str[index] == alphabet[inner_index])
			{
				str[index] = rot13[inner_index];
				break;
			}
		}
	}

	return (str);
}
