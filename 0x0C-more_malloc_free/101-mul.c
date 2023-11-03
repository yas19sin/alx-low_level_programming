#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 if successful, 98 if arguments are incorrect or non-numeric
*/
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);

	if (!is_numeric(argv[1]) || !is_numeric(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	printf("%d\n", num1 * num2);
	return (0);
}

/**
 * is_numeric - Checks if a string contains only numeric characters
 * @str: The input string
 *
 * Return: 1 if numeric, 0 otherwise
*/
int is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
