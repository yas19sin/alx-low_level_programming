#include "main.h"
/**
 * _strstr - Locates a substring
 * @haystack: The string to search
 * @needle: The substring to find
 * Return: A pointer to the beginning of the located substring,
 * or NULL if not found
*/
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *h = haystack;
		char *n = needle;

		while (*n && *h == *n)
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return (haystack);

		haystack++;
	}

	return (0);
}
