#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array containing the program command-line arguments
 *
 * Return: 0 (Success) or 1 (Error)
*/
int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Error\n");
		return (1);
	}

	int cents = atoi(argv[1]);

		if (cents < 0) {
		printf("0\n");
		return (0);
	}

	int coins[] = {25, 10, 5, 2, 1};
	int num_coins = sizeof(coins) / sizeof(coins[0]);
	int min_coins = 0;

	for (int i = 0; i < num_coins; i++) {
		while (cents >= coins[i]) {
			cents -= coins[i];
			min_coins++;
		}
	}

	printf("%d\n", min_coins);
	return (0);
}
