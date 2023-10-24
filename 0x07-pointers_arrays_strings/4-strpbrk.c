#include "main.h"
/**
 * \_strpbrk - Searches a string for any set of bytes
 * @s: The string to search
 * @accept: The string containing bytes to search for
 * Return: A pointer to the byte in s that matches one of the bytes in accept
*/
char *_strpbrk(char *s, char *accept)
{
	while (*s)
	{
		char *a = accept;
		while (*a)
		{
			if (*s == *a)
				return (s);
			a++;
		}
		s++;
	}

	return (0);
}
