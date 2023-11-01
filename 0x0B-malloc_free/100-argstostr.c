#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * argstostr - Concatenates all the arguments of your program.
 * @ac: The argument count
 * @av: The argument vector
 *
 * Return: A pointer to the concatenated string, or NULL if it fails
*/
char *argstostr(int ac, char **av)
{
	char *concatenated;
	int i, k, len = 0, totalLen = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (k = 0; av[i][k] != '\0'; k++)
			len++;
		totalLen += len + 1;
		len = 0;
	}

	concatenated = malloc((totalLen + 1) * sizeof(char));
	if (concatenated == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (k = 0; av[i][k] != '\0'; k++)
			concatenated[len++] = av[i][k];
		concatenated[len++] = '\n';
	}

	concatenated[len] = '\0';

	return (concatenated);
}
