#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all arguments of a program.
 * @ac: The number of arguments.
 * @av: An array of strings containing the arguments.
 *
 * Return: a pointer to a new string, or NULL if it fails.
 */

char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k = 0, len = 0;

	/* Check for invalid input */
	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate the length of the concatenated string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		len++; /* Add 1 for the \n character */
	}

	/* Allocate memory for the concatenated string */
	str = malloc(sizeof(char) * (len + 1));

	/* Concatenate the arguments into the string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			str[k++] = av[i][j];
		str[k++] = '\n';
	}
	str[k] = '\0';

	return (str);
}
