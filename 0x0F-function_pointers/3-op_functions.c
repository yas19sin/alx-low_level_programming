#include <stdio.h>
#include <stdlib.h>

/**
 * op_add - Addition
 * @a: sumnd 1
 * @b: sumnd 2
 * Return: rsult
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Subtraction
 * @a: minuend
 * @b: sustrnd
 * Return: result
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Multiplication
 * @a: multp 1
 * @b: multp 2
 * Return: result
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Division
 * @a: divisr
 * @b: dividndo
 * Return: reult
 */

int op_div(int a, int b)
{
	if (b)
	{
		return (a / b);
	}
	printf("Error\n");
	exit(100);
}

/**
 * op_mod - Modulo
 * @a: vaper 1
 * @b: vaper 2
 * Return: result
 */

int op_mod(int a, int b)
{
	if (b)
	{
		return (a % b);
	}
	printf("Error\n");
	exit(100);
}
