#include "main.h"
#include <stdlib.h>
/**
 * argstostr - Concatenates all the arguments of the program
 * @ac: The number of arguments
 * @av: An array of arguments
 * Return: A pointer to the concatenated string, or NULL on failure
*/
char *argstostr(int ac, char **av)
{
	char *concatenated;
	int i, j, k, len = 0, totalLen = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len])
		{
			len++;
			totalLen++;
		}
	}

	concatenated = (char *)malloc(totalLen + ac + 1);

	if (concatenated == NULL)
		return (NULL);

	for (i = 0, k = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len])
		{
			concatenated[k] = av[i][len];
			len++;
			k++;
		}
		concatenated[k] = '\n';
		k++;
	}
	concatenated[k] = '\0';

	return (concatenated);
}
