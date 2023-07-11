#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed.
 *         0 if the file cannot be opened or read, or if filename is NULL.
 *         0 if the write fails or does not write the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char *buffer;
	ssize_t read_bytes, written_bytes;

	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	buffer = malloc(sizeof(char) * (letters + 1));
	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}

	read_bytes = fread(buffer, sizeof(char), letters, file);
	if (read_bytes == 0)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	written_bytes = fwrite(buffer, sizeof(char), read_bytes, stdout);
	if (written_bytes != read_bytes)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	free(buffer);
	fclose(file);

	return (written_bytes);
}
