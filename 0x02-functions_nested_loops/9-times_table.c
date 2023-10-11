#include "main.h"
/**
 * times_table - prints the 9 times table
*/
void times_table(void)
{
	int row, column, product;

	for (row = 0; row <= 9; row++)
	{
		_putchar('0');

		for (column = 1; column <= 9; column++)
		{
			_putchar(',');

			product = row * column;

			if (product < 10)
			{
				_putchar(' ');
			}

			_putchar('0' + product);
		}

		_putchar('\n');
	}
}
