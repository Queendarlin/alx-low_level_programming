#include "main.h"

/**
 * argstostr - Function to concatenate arguments
 * @ac: The number of command-line argument
 * @av: The command-line argument
 * Return: A pointer to the string or NULL
 */
char *argstostr(int ac, char **av)
{
	char *conc;
	int total_length = 0, current_position = 0;
	int index, arg_length;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (index = 0; index < ac; index++)
	{
		if (av[index] != NULL)
		{
			arg_length = 0;

			while (av[index][arg_length] != '\0')
			{
				arg_length++;
			}
			total_length += arg_length + 1;
		}
	}
	conc = malloc(sizeof(char) * (total_length + 1));
	if (conc == NULL)
		return (NULL);
	for (index = 0; index < ac; index++)
	{
		if (av[index] != NULL)
		{
			arg_length = 0;

			while (av[index][arg_length] != '\0')
			{
				conc[current_position] = av[index][arg_length];
				arg_length++;
				current_position++;
			}
			conc[current_position] = '\n';
			current_position++;
		}
	}
	conc[total_length] = '\0';
	return (conc);
}
