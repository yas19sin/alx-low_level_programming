#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array containing the program command-line arguments
 *
 * Return: 0 (Success) or 1 (Error)
*/
int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("Error\n");
		return (1);
	}

	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);

	printf("%d\n", num1 * num2);
	return (0);
}
