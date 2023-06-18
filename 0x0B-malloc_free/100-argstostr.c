#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * argstostr - concatenates all the arguments of the program.
 * @ac: number of arguments.
 * @av: array of arguments.
 *
 * Return: a pointer to the  a new string, or NULL if it fails.
 * Returns NULL if ac == 0 or av == NULL
 */

char *argstostr(int ac, char **av)
{
	int i, j;
	int len = 0;
	int total_len = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		len = strlen(av[i]);
		total_len += len + 1;
	}

	str = malloc(total_len * sizeof(char));

	if (str == NULL)
		return (NULL);

	total_len = 0;

	for (i = 0; i < ac; i++)
	{
		len = strlen(av[i]);

		for (j = 0; j < len; j++)
		{
			str[total_len] = av[i][j];
			total_len++;
		}

		str[total_len] = '\n';
		total_len++;
	}

	str[total_len] = '\0';

	return (str);
}
