#include "main.h"
/**
 * infinite_add - adds two numbers as strings
 * @n1: first number as string
 * @n2: second number as string
 * @r: buffer to store the result
 * @size_r: size of the buffer
 * Return: pointer to the result, or 0 if the result cannot be stored
*/
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = 0, len2 = 0, carry = 0, i, sum;

    while (n1[len1])
        len1++;
    while (n2[len2])
        len2++;

    if (len1 + 2 > size_r || len2 + 2 > size_r)
        return (0);

    len1--;
    len2--;
    r[size_r] = '\0';
    for (i = size_r - 2; len1 >= 0 || len2 >= 0 || carry; i--)
    {
        sum = carry;
        if (len1 >= 0)
            sum += n1[len1] - '0';
        if (len2 >= 0)
            sum += n2[len2] - '0';
        carry = sum / 10;
        r[i] = (sum % 10) + '0';
        if (len1 >= 0)
            len1--;
        if (len2 >= 0)
            len2--;
    }
    if (i < 0)
        return (0);

    return (r + i + 1);
}
