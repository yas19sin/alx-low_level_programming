#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always 0
*/
int main(void)
{
	long int a = 1, b = 2, next;
	int count;

	_putchar('1');
	_putchar(',');
	_putchar(' ');

	_putchar('2');
	for (count = 3; count <= 50; count++)
	{
		next = a + b;
		_putchar(',');
		_putchar(' ');
		print_number(next);
		a = b;
		b = next;
	}
	_putchar('\n');

	return (0);
}
