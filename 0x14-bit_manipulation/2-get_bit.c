#include "main.h"
/**
 * get_bit - Gets the value of a bit at a given index
 * @n: Unsigned long int
 * @index: Index of the bit
 *
 * Return: Value of the bit at the index or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	return ((n >> index) & 1);
}
