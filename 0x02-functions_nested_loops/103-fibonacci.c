#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always 0
*/
int main(void)
{
	long int a = 1, b = 2, next, sum = 2;

	while (1)
	{
		next = a + b;
		if (next > 4000000)
			break;
		if (next % 2 == 0)
			sum += next;
		a = b;
		b = next;
	}

	print_number(sum);
	_putchar('\n');

	return (0);
}
