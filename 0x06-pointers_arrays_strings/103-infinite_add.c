#include "main.h"

/**
 * reverse_string - Function to reverse array of characters
 * @str: Reversed string
 */
void reverse_string(char *str)
{
	int start = 0;
	int end = 0;
	char temp;

	while (*(str + end) != '\0')
	{
		end++;
	}
	end--;

	for (start = 0; start < end; start++, end--)
	{
		temp = *(str + start);
		*(str + start) = *(str + end);
		*(str + end) = temp;
	}
}
/**
 * infinite_add - Function to add two numbers
 * @n1: First number to be added
 * @n2: Second number to be added
 * @r: Buffer to store the addition result
 * @size_r: Size of the buffer
 * Return: Pointer to r or 0 if result cannot be stored
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int carry = 0;
	int index_n1 = 0;
	int index_n2 = 0;
	int result_digits = 0;
	int value1 = 0;
	int value2 = 0;
	int holder = 0;

	while (*(n1 + index_n1) != '\0')
		index_n1++;
	while (*(n2 + index_n2) != '\0')
		index_n2++;
	index_n1--;
	index_n2--;
	if (index_n2 >= size_r || index_n1 >= size_r)
		return (0);
	while (index_n2 >= 0 || index_n1 >= 0 || carry == 1)
	{
		if (index_n1 < 0)
			value1 = 0;
		else
			value1 = *(n1 + index_n1) - '0';
		if (index_n2 < 0)
			value2 = 0;
		else
			value2 = *(n2 + index_n2) - '0';
		holder = value1 + value2 + carry;
		if (holder >= 10)
			carry = 1;
		else
			carry = 0;
		if (result_digits >= (size_r - 1))
			return (0);
		*(r + result_digits) = (holder % 10) + '0';
		result_digits++;
		index_n2--;
		index_n1--;
	}
	if (result_digits == size_r)
		return (0);
	*(r + result_digits) = '\0';
	reverse_string(r);
	return (r);
}
