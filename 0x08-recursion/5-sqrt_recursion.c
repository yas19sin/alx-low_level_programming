#include "main.h"
/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 * Return: The square root of n or -1 if it doesn't exist.
*/
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_helper(n, 1));
}

/**
 * sqrt_helper - A helper function to find the square root.
 * @n: The number to find the square root of.
 * @i: The current guess.
 * Return: The square root of n or -1 if it doesn't exist.
*/
int sqrt_helper(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (sqrt_helper(n, i + 1));
}
