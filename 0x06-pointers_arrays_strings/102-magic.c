#include "main.h"
#include <stdio.h>
/**
 * main - Entry point of the program
 *
 * Description: Initializes an integer array, assigns values,
 * and prints a result.
 *
 * Return: Always 0 (Success)
*/
int main(void)
{
	int n;
	int a[5];
	int *p;

	a[2] = 1024;
	p = &n;

	p[5] = 98;

	printf("a[2] = %d\n", a[2]);

	return (0);
}
