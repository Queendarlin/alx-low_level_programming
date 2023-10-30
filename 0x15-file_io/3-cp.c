#include "main.h"


/**
 * open_source_file - Opens the source file for reading.
 * @filename: The name of the source file.
 * Return: The file descriptor of the opened source file or -1 on failure.
 */
int open_source_file(const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", filename);
	}
	return (fd);
}

/**
 * open_destination_file - Opens the destination file for writing.
 *
 * @filename: The name of the destination file.
 *
 * Return: The file descriptor of the opened destination file or -1 on failure.
 */
int open_destination_file(const char *filename)
{
	int fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd == -1)
	{
		dprintf(2, "Error: Can't write to file %s\n", filename);
	}
	return (fd);
}

/**
 * copy_file - Copies the content from the source file to the destination file.
 *
 * @source_fd: The file descriptor of the source file.
 * @dest_fd: The file descriptor of the destination file.
 *
 * Return: 0 on success, -1 on failure.
 */
int copy_file(int source_fd, int dest_fd)
{
	char buffer[BUFSIZE];
	ssize_t rd, wr;

	while ((rd = read(source_fd, buffer, BUFSIZE) > 0))
	{
		wr = write(dest_fd, buffer, rd);

		if (wr == -1)
		{
			dprintf(2, "Error: Can't write to file descriptor\n");
			return (-1);
		}
	}

	if (rd == -1)
	{
		dprintf(2, "Error: Can't read from file descriptor\n");
		return (-1);
	}

	return (0);
}

/**
 * main - Copies the content of a file to another file.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	int source_fd;
	int dest_fd;

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		return (97);
	}

	source_fd = open_source_file(argv[1]);
	if (source_fd == -1)
	{
		return (98);
	}
	dest_fd = open_destination_file(argv[2]);

	if (dest_fd == -1)
	{
		return (99);
	}

	if (copy_file(source_fd, dest_fd) == -1)
	{
		return (99);
	}
	if (close(source_fd) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", source_fd);
		return (100);
	}
	if (close(dest_fd) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", dest_fd);
		return (100);
	}

	return (0);
}
