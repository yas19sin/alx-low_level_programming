#include <stdio.h>
/**
 * main - Prints the lowercase and uppercase alphabets followed by a newline.
 *
 * Return: Always 0 (Success)
*/
int main(void)
{
    char letter = 'a';

    while (letter <= 'z')
    {
        putchar(letter);
        letter++;
    }

    letter = 'A';

    while (letter <= 'Z')
    {
        putchar(letter);
        letter++;
    }

    putchar('\n');

    return (0);
}
