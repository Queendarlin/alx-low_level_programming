#include "main.h"

/**
 * read_textfile - Reads a text file and writes it to standard output.
 * @filename: The name of the text file to read.
 * @letters: The number of bytes to read and print.
 *
 * Return: Number of bytes successfully read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer_stor;
	ssize_t fileD;
	ssize_t num_bytes_w;
	ssize_t num_bytes_r;

	fileD = open(filename, O_RDONLY);
	if (fileD == -1)
		return (0);

	buffer_stor = malloc(sizeof(char) * letters);
	num_bytes_r = read(fileD, buffer_stor, letters);
	num_bytes_w = write(STDOUT_FILENO, buffer_stor, num_bytes_r);

	free(buffer_stor);
	close(fileD);

	return (num_bytes_w);
}
