#include "main.h"

/**
 * create_file - Creates a file and writes text content to it.
 * @filename: The name of the file to create.
 * @text_content: The text content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, write_result, close_result;
	size_t text_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[text_length])
			text_length++;
	}

	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file_descriptor == -1)
		return (-1);

	write_result = write(file_descriptor, text_content, text_length);
	if (write_result == -1)
	{
		close(file_descriptor);
		return (-1);
	}

	close_result = close(file_descriptor);
	if (close_result == -1)
		return (-1);

	return (1);
}
