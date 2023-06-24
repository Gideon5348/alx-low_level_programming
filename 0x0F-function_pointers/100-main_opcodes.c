#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the arguments
 *
 * Return: 0 on success, 1 if incorrect number of arguments,
 * 2 if negative bytes
 */

int main(int argc, char *argv[])
{
	int num_of_bytes, i;
	char *main_ptr;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num_of_bytes = atoi(argv[1]);

	if (num_of_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	main_ptr = (char *)main;

	for (i = 0; i < num_of_bytes; i++)
	{
		printf("%02hhx", main_ptr[i]);
		if (i < num_of_bytes - 1)
			printf(" ");
	}

	printf("\n");

	return (0);
}
