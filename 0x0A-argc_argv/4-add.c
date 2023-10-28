
#include <stdio.h>
#include <stdlib.h>

int is_digit(char *s) {
    for (int i = 0; s[i]; i++) {
        if (s[i] < '0' || s[i] > '9') {
            return 0;
        }
    }
    return 1;
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array containing the program command-line arguments
 *
 * Return: 0 (Success) or 1 (Error)
*/
int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("0\n");
		return (0);
	}

	int sum = 0;

	for (int i = 1; i < argc; i++) {
		if (is_digit(argv[i])) {
			sum += atoi(argv[i]);
		} else {
			printf("Error\n");
			return (1);
		}
	}

	printf("%d\n", sum);
	return (0);
}
