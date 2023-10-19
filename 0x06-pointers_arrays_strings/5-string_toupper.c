#include "main.h"
/**
 * string_toupper - converts lowercase letters to uppercase in a string
 * @str: input string
 * Return: pointer to the resulting string
*/
char *string_toupper(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}

	return (str);
}
