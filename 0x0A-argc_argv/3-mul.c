#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _isdigit - checks if a character is a digit (0-9)
 * @c: the character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */

int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the converted integer
 */

int _atoi(char *s)
{
	int y = 0;
	int sign = 1;
	int outcome = 0;

	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			sign = -1;

		y++;
	}

	while (s[y])
	{
		if (!_isdigit(s[y]))
			break;
		outcome = outcome * 10 + (s[y] - '0');
		y++;
	}

	return (outcome * sign);
}

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
	{
		printf("Error\n");

		return (1);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	outcome = num1 * num2;

	printf("%d\n", outcome);

	return (0);
}
