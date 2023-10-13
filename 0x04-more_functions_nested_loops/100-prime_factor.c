#include <stdio.h>
#include <math.h>
/**
 * main - finds and prints the largest prime factor of 612852475143
 *
 * Return: Always 0
*/
int main(void)
{
	long number = 612852475143;
	long largest_prime = -1;
	long divisor = 2;

	while (number != 1)
	{
		if (number % divisor == 0)
		{
			largest_prime = divisor;
			number = number / divisor;
		}
		else
		{
			divisor++;
		}
	}

	printf("%ld\n", largest_prime);

	return (0);
}
