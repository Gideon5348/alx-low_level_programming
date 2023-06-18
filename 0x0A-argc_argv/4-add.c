#include <stdio.h>
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

	/* Handle leading '+' or '-' */
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			sign = -1;
		y++;
	}

	/* Convert the remaining digits */
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
	int y, sum = 0;

	if (argc < 2)
	{
		printf("0\n");
		return (0);
	}

	for (y = 1; y < argc; y++)
	{
		char *num = argv[y];

		while (*num)
		{
			if (!_isdigit(*num))
			{
				printf("Error\n");
				return (1);
			}
			num++;
		}

		sum += _atoi(argv[y]);
	}

	printf("%d\n", sum);

	return (0);
}
