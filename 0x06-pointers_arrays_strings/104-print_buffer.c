#include "main.h"

/**
 * print_buffer - Function to print a buffer
 * @b: Pointer to the buffer to be printed
 * @size: Number of bytes to be printed
 */
void print_buffer(char *b, int size)
{
	int start_buff, bytes_to_print, i;

	start_buff = 0;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	while (start_buff < size)
	{
		bytes_to_print = size - start_buff < 10 ? size - start_buff : 10;
		printf("%08x: ", start_buff);
		for (i = 0; i < 10; i++)
		{
			if (i < bytes_to_print)
				printf("%02x", *(b + start_buff + i));
			else
				printf("  ");
			if (i % 2)
			{
				printf(" ");
			}
		}
		for (i = 0; i < bytes_to_print; i++)
		{
			int c = *(b + start_buff + i);

			if (c < 32 || c > 132)
			{
				c = '.';
			}
			printf("%c", c);
		}
		printf("\n");
		start_buff += 10;
	}
}
