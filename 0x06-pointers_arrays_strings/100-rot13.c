#include "main.h"
/**
 * rot13 - encodes a string using rot13
 * @str: input string
 * Return: pointer to the resulting string
*/
char *rot13(char *str)
{
	int i = 0;
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			int index = 0;

			while (alpha[index] != '\0')
			{
				if (str[i] == alpha[index])
				{
					str[i] = rot13[index];
					break;
				}
				index++;
			}
		}
		i++;
	}

	return (str);
}
