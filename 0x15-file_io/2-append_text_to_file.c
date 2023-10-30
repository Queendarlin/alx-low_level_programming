#include "main.h"

/**
 * append_text_to_file - Function to append text at the end of a file
 * @filename: The file to append to
 * @text_content: The NULL-terminated string to add at the end of the file
 * Return: (1) on success and (-1) on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_D;
	ssize_t num_bytes_w;

	if (filename == NULL)
		return (-1);

	file_D = open(filename, O_WRONLY | O_APPEND);

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
