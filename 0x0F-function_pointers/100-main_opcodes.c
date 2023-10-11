#include <stdio.h>
#include <stdlib.h>

/**
 * main - Function to print the opcodes of its own main function.
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success, 1 on incorrect arguments, 2 on negative byte count.
 */
int main(int argc, char *argv[])
{
	int num_bytes;
	char *main_ptr;
	int index;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	main_ptr = (char *)main;

	for (index = 0; index < num_bytes; index++)
	{
		if (index == num_bytes - 1)
		{
			printf("%02hhx\n", main_ptr[index]);
		}
		else
		{
			printf("%02hhx ", main_ptr[index]);
		}
	}

	return (0);
}
