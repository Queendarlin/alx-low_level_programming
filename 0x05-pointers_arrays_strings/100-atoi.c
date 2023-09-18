#include "main.h"

/**
 * _atoi - Function to convert a string to an integer
 * @s: string to be converted
 *
 * Return: Returns 0 or the numbers in the string
 */
int _atoi(char *s)
{
	int i = 0;
	int minusCount = 0;
	int result = 0;
	int sLength = 0;
	int digitFound = 0;
	int currentDigit = 0;

	while (s[sLength] != '\0')
	{
		sLength++;
	}

	while (i < sLength && digitFound == 0)
	{
		if (s[i] == '-')
			++minusCount;

		if (s[i] >= '0' && s[i] <= '9')
		{
			currentDigit = s[i] - '0';

			if (minusCount % 2)
				currentDigit = -currentDigit;

			result = result * 10 + currentDigit;

			digitFound = 1;

			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;

			digitFound = 0;
		}
		i++;
	}

	if (digitFound == 0)
		return (0);

	return (result);
}
