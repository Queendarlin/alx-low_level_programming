#include "3-calc.h"

/**
 * main - Entry point of the program
 * @argc: The number of command line arguments
 * @argv: An array of pointers to the command line arguments
 *
 * Return: 0 on success
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int par1, par2;
	char *cal;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	par1 = atoi(argv[1]);
	cal = argv[2];
	par2 = atoi(argv[3]);

	if (get_op_func(cal) == NULL || cal[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	if ((*cal == '/' && par2 == 0) ||
	    (*cal == '%' && par2 == 0))
	{
		printf("Error\n");
		exit(100);
	}
	printf("%d\n", get_op_func(cal)(par1, par2));

	return (0);
}

