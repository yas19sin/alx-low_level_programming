#include "main.h"
#include <stdio.h>
/**
 * print_buffer - prints a buffer
 * @b: the buffer to print
 * @size: the number of bytes to print
*/
void print_buffer(char *b, int size)
{
    int i, j;

    for (i = 0; i < size; i += 10)
    {
        printf("%08x: ", i);

        for (j = 0; j < 10; j++)
        {
            if (j + i >= size)
                printf("  ");
            else
                printf("%02x", b[i + j]);
            if (j % 2)
                printf(" ");
        }

        for (j = 0; j < 10; j++)
        {
            if (j + i >= size)
                break;
            if (b[i + j] >= 32 && b[i + j] <= 126)
                printf("%c", b[i + j]);
            else
                printf(".");
        }
        printf("\n");
    }

    if (size <= 0)
        printf("\n");
}
