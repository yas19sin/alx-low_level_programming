#include "main.h"
/**
 * create_file - Create a new file with the given text content.
 * @filename: The name of the file to be created.
 * @text_content: The text content to write to the file.
 * Return: Returns 1. On failure or error, returns -1.
*/
int create_file(const char *filename, char *text_content)
{
	int fd;
	int len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	while (text_content && text_content[len])
		len++;

	write(fd, text_content, len);
	close(fd);
	return (1);
}
