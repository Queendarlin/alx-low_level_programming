#include "main.h"

/**
 * count_word - Function to support and count the number of words in a string
 * @s: The string to check
 *
 * Return: The number of words
 */
int count_word(char *s)
{
	int current_word = 0, a, wc = 0;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (s[a] == ' ')
			current_word = 0;
		else if (current_word == 0)
		{
			current_word = 1;
			wc++;
		}
	}
	return (wc);
}
/**
 * strtow - Function to split a string into words
 * @str: The string to split
 *
 * Return: pointer to an array of strings or NULL
 */
char **strtow(char *str)
{
	char **wordArray, *space;
	int i, index = 0, length = 0, words, current_word = 0, start, end;

	while (*(str + length))
		length++;
	words = count_word(str);
	if (words == 0)
		return (NULL);
	wordArray = malloc(sizeof(char *) * (words + 1));
	if (wordArray == NULL)
		return (NULL);
	for (i = 0; i <= length; i++)
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (current_word)
			{
				end = i;
				space = malloc(sizeof(char) * (current_word + 1));
				if (space == NULL)
				{
					for (index = 0; index < i; index++)
					{
						free(wordArray[index]);
					}
					free(wordArray);
					return (NULL);
				}
				while (start < end)
					*space++ = str[start++];
				*space = '\0';
				wordArray[index] = space - current_word;
				index++;
				current_word = 0;
			}
		}
		else if (current_word++ == 0)
			start = i;
	wordArray[index] = NULL;
	return (wordArray);
}
