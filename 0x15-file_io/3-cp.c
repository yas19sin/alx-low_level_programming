#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * copy_file - Copies the content of one file to another
 * @file_from: Source file
 * @file_to: Destination file
 * Return: 0 on success, -1 on failure
*/
int copy_file(const char *file_from, const char *file_to)
{
	if (file_from == NULL || file_to == NULL)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	int fd_src = open(file_from, O_RDONLY);

	if (fd_src == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	int fd_dest = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_dest == -1)
	{
		dprintf(2, "Error: Can't write to file %s\n", file_to);
		exit(99);
	}

	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_src, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_dest, buffer, (size_t)bytes_read);
		if (bytes_written == -1) {
			dprintf(2, "Error: Can't write to file %s\n", file_to);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	if (close(fd_src) == -1 || close(fd_dest) == -1)
	{
		dprintf(2, "Error: Can't close fd\n");
		exit(100);
	}

	return 0;
}
