#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function.
 * @argc: number of arguments passed to the program
 * @argv: array of strings with the arguments passed
 *
 * Return: Always 0 (Success)
 * If the number of argument is not the correct one, print Error,
 * followed by a new line, and exit with the status 1
 * If the number of bytes is negative, print Error,
 * followed by a new line, and exit with the status 2
 */

int main(int argc, char **argv)
{
	int num_bytes, i;
	unsigned char *ptr;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	ptr = (unsigned char *)main;

	for (i = 0; i < num_bytes - 1; i++)
	{
		printf("%.2x ", *(ptr + i));
	}

	printf("%.2x\n", *(ptr + i));

	return (0);
}
