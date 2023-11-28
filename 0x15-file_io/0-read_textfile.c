#include "main.h"
/**
 * read_textfile - Read and print the contents of a text file.
 * @filename: The name of the file to read from.
 * @letters: The number of letters to read and print.
 * Return: Returns the actual number of letters read. On failure or
 * error, returns 0.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t bytes, i;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY, 0777);

	if (fd == -1)
		return (0);

	buffer = malloc(letters * sizeof(char));

	if (!buffer)
		return (0);

	bytes = read(fd, buffer, letters);

	if (bytes == -1)
	{
		free(buffer);
		return (0);
	}

	for (i = 0; i < bytes; i++)
	{
		write(STDOUT_FILENO, &buffer[i], 1);
	}

	if (close(fd) == -1)
		return (0);

	free(buffer);
	return (bytes);
}
