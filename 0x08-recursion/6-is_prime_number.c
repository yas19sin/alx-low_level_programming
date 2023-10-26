#include "main.h"
/**
 * is_prime_number - Checks if a number is prime.
 * @n: The number to be checked.
 * Return: 1 if prime, 0 if not.
*/
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (is_prime_helper(n, 2));
}

/**
 * is_prime_helper - Helper function to check for primality.
 * @n: The number to be checked.
 * @i: The current divisor.
 * Return: 1 if prime, 0 if not.
*/
int is_prime_helper(int n, int i)
{
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
	return (is_prime_helper(n, i + 1));
}
