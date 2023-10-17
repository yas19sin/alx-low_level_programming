#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
*/
int main(void)
{
	char password[84];
	int sum, n, i;

	sum = 0;
	n = 0;
	srand(time(0));

	while (sum < 2772 - 122)
	{
		password[n] = rand() % 90 + 33;
		sum += password[n];
		n++;
	}

	password[n] = 2772 - sum - 0;
	password[n + 1] = '\0';

	for (i = 0; i < n + 1; i++)
	{
		putchar(password[i]);
	}

	return (0);
}
