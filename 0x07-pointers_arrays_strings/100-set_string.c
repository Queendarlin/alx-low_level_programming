#include "main.h"

/**
 * set_string - Function to set the value of a pointer to a char
 * @s: Pointer to a pointer to char, the pointer to be modified
 * @to: Pointer to the char to set the pointer 's' to
 */
void set_string(char **s, char *to)
{
	*s = to;
}
