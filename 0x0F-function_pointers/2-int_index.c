#include "function_pointers.h"
/**
 * int_index - searches for an integer
 * @array: array to search
 * @size: size of the array
 * @cmp: pointer to the comparison function
 *
 * Return: index of first matching element, -1 if not found or on error
*/
int int_index(int *array, int size, int (*cmp)(int))
{
	if (array && cmp && size > 0)
	{
		int i;

		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
				return (i);
		}
	}
	return (-1);
}
