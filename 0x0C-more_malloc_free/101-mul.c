#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Multiplies two positive numbers
 * @argc: The number of arguments
 * @argv: The arguments
 * Return: 0 if successful, 98 if incorrect arguments, 1 if not a number
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error\n");
        exit(98);
    }

    int len1 = 0, len2 = 0, i, j, carry = 0;
    int *result;
    int num1, num2, product;

    while (argv[1][len1])
    {
        if (argv[1][len1] < '0' || argv[1][len1] > '9')
        {
            printf("Error\n");
            exit(98);
        }
        len1++;
    }

    while (argv[2][len2])
    {
        if (argv[2][len2] < '0' || argv[2][len2] > '9')
        {
            printf("Error\n");
            exit(98);
        }
        len2++;
    }

    result = malloc(len1 + len2);

    if (result == NULL)
    {
        printf("Error\n");
        exit(98);
    }

    for (i = len1 - 1; i >= 0; i--)
    {
        num1 = argv[1][i] - '0';
        carry = 0;

        for (j = len2 - 1; j >= 0; j--)
        {
            num2 = argv[2][j] - '0';
            product = num1 * num2 + result[i + j + 1] + carry;
            carry = product / 10;
            result[i + j + 1] = product % 10;
        }
        result[i + j + 1] += carry;
    }

    if (result[0] == 0)
        i = 1;
    else
        i = 0;

    for (; i < len1 + len2; i++)
        printf("%d", result[i]);

    printf("\n");
    free(result);

    return (0);
}

