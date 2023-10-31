#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 1 on error
*/
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	int mul = 0;

	for (i = 1; i < argc; i++)
	{
		val *= atoi(argv[i]);
	}

	printf("%d\n", mul);

	return (0);
}
