#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always 0
*/
int main(void)
{
	int i;
	long fib1 = 1, fib2 = 2, temp;

	printf("%ld, %ld", fib1, fib2);

	for (i = 2; i < 98; i++)
	{
		temp = fib1 + fib2;
		printf(", %ld", temp);
		fib1 = fib2;
		fib2 = temp;
    }

	printf("\n");
	return (0);
}
