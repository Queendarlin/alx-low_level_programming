#include "main.h"

/**
 * is_space - Function to check if a character is a whitespace character.
 * @c: The character to check.
 *
 * Return: 1 if @c is a whitespace character, 0 otherwise.
 */
int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
}

/**
 * strtow - Splits a string into words.
 * @str: The input string to split.
 *
 * Return: (char **) A pointer to an array of strings (words). The last element of the array is NULL.
 *         Returns NULL if @str is NULL or an empty string, or if memory allocation fails.
 */
char **strtow(char *str)
{
	int word_count = 0, in_word = 0, word_index = 0;
	char **words = NULL, *ptr = NULL, *word_start = NULL;
	int index;

	if (str == NULL || *str == '\0')
		return (NULL);
	for (ptr = str; *ptr != '\0'; ptr++)
	{
		if (!is_space(*ptr))
		{
			if (!in_word)
			{
				word_count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
	}
	words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	in_word = 0;

	for (ptr = str; *ptr != '\0'; ptr++)
	{
		if (!is_space(*ptr))
		{
			if (!in_word)
			{
				word_start = ptr;
				in_word = 1;
			}
		}
		else if (in_word)
		{
			int word_length = ptr - word_start;
			words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
			if (words[word_index] == NULL)
			{
				for (index = 0; index < word_index; index++)
					free(words[index]);
				free(words);
				return (NULL);
			}
			strncpy(words[word_index], word_start, word_length);
			words[word_index][word_length] = '\0';
			word_index++;
			in_word = 0;
		}
	}
	words[word_index] = NULL;
	return (words);
}
