#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: Computes and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2, separated by a comma and space,
 * followed by a new line.
 *
 * Return: 0 (Success)
*/
int main(void)
{
	int count;
	unsigned long int a = 1, b = 2, next;

	printf("%lu, %lu", a, b);

	for (count = 2; count < 98; count++)
	{
		next = a + b;
		printf(", %lu", next);
		a = b;
		b = next;
	}

	printf("\n");
	return (0);
}
