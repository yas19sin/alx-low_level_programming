#include "main.h"
/**
 * append_text_to_file - Appends text to an existing file.
 * @filename: The file to which text will be appended.
 * @text_content: The text content to append to the file.
 * Return: Returns 1 on success. On failure or error, returns -1.
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor;
	int content_length = 0;

	if (!filename)
		return (-1);

	file_descriptor = open(filename, O_RDWR | O_APPEND);
	if (file_descriptor == -1)
		return (-1);

	while (text_content && text_content[content_length])
		content_length++;

	write(file_descriptor, text_content, content_length);

	if (close(file_descriptor) == -1)
		return (-1);

	return (1);
}
