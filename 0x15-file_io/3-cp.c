#include "main.h"

#define BUFSIZE 1024

/**
 * create_buff - Allocates 1024 bytes for a buffer.
 * @filename: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buff(char *filename)
{
	char *buff_stor;

	buff_stor = malloc(sizeof(char) * BUFSIZE);

	if (buff_stor == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (buff_stor);
}

/**
 * close_fd - Closes file descriptors.
 * @file_D: The file descriptor to be closed.
 */
void close_fd(int file_D)
{
	int c;

	c = close(file_D);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_D);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, num_bytes_r, num_bytes_w;
	char *buff_stor;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buff_stor = create_buff(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	num_bytes_r = read(file_from, buff_stor, BUFSIZE);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (file_from == -1 || num_bytes_r == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buff_stor);
			exit(98);
		}
		num_bytes_w = write(file_to, buff_stor, num_bytes_r);
		if (file_to == -1 || num_bytes_w == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buff_stor);
			exit(99);
		}
		num_bytes_r = read(file_from, buff_stor, BUFSIZE);
		file_to = open(argv[2], O_WRONLY | O_APPEND);
	} while (num_bytes_r > 0);

	free(buff_stor);
	close_fd(file_from);
	close_fd(file_to);

	return (0);
}
