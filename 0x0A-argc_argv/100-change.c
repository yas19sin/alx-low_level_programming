#include <stdio.h>
#include <stdlib.h>
/**
 * main - Prints the minimum number of coins
 * to make change for an amount of money
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, 1 on error
*/
int main(int argc, char *argv[])
{
	int value, coins = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	value = atoi(argv[1]);

	if (value < 0)
	{
		printf("%d\n", 0);
		return (0);
	}

	while (value > 0)
	{
		if (value >= 25)
			value -= 25;
		else if (value >= 10)
			value -= 10;
		else if (value >= 5)
			value -= 5;
		else if (value >= 2)
			value -= 2;
		else
			value -= 1;
		coins++;
	}

	printf("%d\n", coins);

	return (0);
}
