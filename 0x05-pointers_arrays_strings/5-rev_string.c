#include "main.h"

/**
 * rev_string - Function to reverse a string
 * @s: pointer to the reversed string
 */
void rev_string(char *s)
{
	int index;
	int length = 0;

	for (index = 0;  s[index] != '\0'; index++)
		length++;
	for (index = 0; index < length / 2; index++)
	{
		char holder;

		holder = s[index];
		s[index] = s[length - 1 - index];
		s[length - 1 - index] = holder;
	}
}
