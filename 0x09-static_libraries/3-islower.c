#include "main.h"

/**
 * _islower - The function that checks for lowercase character
 *
 * @c: A parameter for the function
 * Return: Returns 1 if c is lowercase or returns 0 otherwise
 */
int _islower(int c)
{

	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
