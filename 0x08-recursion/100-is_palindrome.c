#include "main.h"

/**
 * length_string - Function to recursively get string length
 *  @s: Pointer to the string to check
 * Return: 1 if the string is palindrome, else 0
 */
int length_string(char *s)
{
	if (*s == '\0')
		return (0);
	else
		return (1 + length_string(s + 1));
}

/**
 * recursive_palindrome - Function to recursively check a palindrome
 * @s: Pointer to the string to check
 * Return: 1 if the string is palindrome, else 0
 * @index: parameter to store the result of string length
 */
int recursive_palindrome(char *s, int index)
{
	if (index <= 1)
		return (1);
	if (*s != s[index - 1])
		return (0);
	return (recursive_palindrome(s + 1, index - 2));
}

/**
 * is_palindrome - Function to check if a string is a palindrome
 * @s: Pointer to the string to check
 *  Return: 1 if the string is palindrome, else 0
 */
int is_palindrome(char *s)
{
	int index = length_string(s);

	return (recursive_palindrome(s, index));
}
