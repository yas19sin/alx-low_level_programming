#include "main.h"

/**
 * print_error - Error code and name to a specific format.
 * @code: The error code to be converted.
 * @name: The name associated with the error code.
 * Return: Always returns 0.
 */
void print_error(int code, char *name)
{
	switch (code)
	{
	case 98:
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", name);
		exit(98);
		break;
	case 99:
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", name);
		exit(99);
		break;
	}
}

/**
 * main - Entry point for the program.
 * @argc: The number of command line arguments.
 * @argv: Ar Strings containing the command line arguments.
 * Return: Always returns 0 to indicate successful execution.
 */
int main(int argc, char *argv[])
{
	int ffrom, fto, wrt = 0, rd = 0;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	ffrom = open(argv[1], O_RDONLY);
	if (ffrom == -1)
		print_error(98, argv[1]);

	fto = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fto == -1)
		print_error(99, argv[2]);

	while ((rd = read(ffrom, buffer, 1024)))
	{
		if (rd == -1)
			print_error(98, argv[1]);
		wrt = write(fto, buffer, rd);
		if (wrt == -1)
			print_error(99, argv[2]);
	}

	if (close(ffrom) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", ffrom);
		exit(100);
	}
	if (close(fto) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fto);
		exit(100);
	}
	return (0);
}
