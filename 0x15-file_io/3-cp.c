#include "main.h"

/**
 * create_buff - Function to allocate 1024 bytes for a buffer
 * @filename: The name of the file
 * Return: The allocated buffer
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
 * close_fd - Function to close the file descriptor
 * @file_D: The file descriptor that needs to be closed
 */
void close_fd(int file_D)
{
	int temp_close;

	temp_close = close(file_D);

	if (temp_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_D);
		exit(100);
	}
}

/**
 * main - Function to copy a file content to another file
 * @argc: The number of arguments
 * @argv:  The second argument
 * Return: 0 on success
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
