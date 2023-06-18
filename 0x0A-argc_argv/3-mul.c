#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the name of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int num1, num2, outcome;

	if (argc != 3)
		printf("Error\n");

	return (1);

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	outcome = num1 * num2;

	printf("%d\n", outcome);

	return (0);
}
