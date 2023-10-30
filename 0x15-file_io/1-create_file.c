#include "main.h"

/**
 * create_file - Function to create a file with the specified permissions
 * @filename: The name of the file to create
 * @text_content: The text content to write to the file
 * Return: 1 on success or -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_D;
	ssize_t num_bytes_w;

	if (filename == NULL)
		return (-1);

	file_D = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file_D == -1)
		return (-1);
	if (text_content != NULL)
	{
		num_bytes_w = write(file_D, text_content, strlen(text_content));
		if (num_bytes_w == -1)
		{
			close(file_D);
			return (-1);
		}
	}

	close(file_D);
	return (1);
}
