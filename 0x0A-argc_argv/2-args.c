#include <stdio.h>
/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0
*/
int main(int argc, char *argv[])
{
        for (int i = 0; i < argc; i++)
        {
                printf("%s\n", argv[i]);
        }
        return (0);
}
