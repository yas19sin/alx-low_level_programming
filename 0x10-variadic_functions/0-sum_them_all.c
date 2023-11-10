#include "variadic_functions.h"
/**
 * sum_them_all - Returns the sum of its parameters.
 * @n: Number of parameters
 * @...: Parameters
 *
 * Return: Sum of parameters
*/
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int sum = 0;

	va_start(args, n);
	for (i = 0; i < n; i++)
		sum += va_arg(args, int);
	va_end(args);

	return (sum);
}
