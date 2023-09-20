#include "main.h"

/**
 * cap_string - Function to capitalizes all words of a string
 * @str: The string that will be capitalized
 *
 * Return: A pointer to str
 */
char *cap_string(char *str)
{
	int word_index;

	for (word_index = 0; str[word_index] != '\0'; word_index++)
	{
		while (!(str[word_index] >= 'a' && str[word_index] <= 'z'))
			word_index++;

		if (str[word_index - 1] == ' ' ||
				str[word_index - 1] == '\t' ||
				str[word_index - 1] == '\n' ||
				str[word_index - 1] == ',' ||
				str[word_index - 1] == ';' ||
				str[word_index - 1] == '.' ||
				str[word_index - 1] == '!' ||
				str[word_index - 1] == '?' ||
				str[word_index - 1] == '"' ||
				str[word_index - 1] == '(' ||
				str[word_index - 1] == ')' ||
				str[word_index - 1] == '{' ||
				str[word_index - 1] == '}' ||
				word_index == 0)
		{
			str[word_index] -= 32;
		}
	}
	return (str);
}
