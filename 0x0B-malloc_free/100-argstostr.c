#include "main.h"
#include <stdio.h>
#include <stdlib.h>

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
	int i, j, len, total_len;
	char *str, *concat_str;

	if (ac == 0 || av == NULL)
		return (NULL);

	total_len = 0;
	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len])
			len++;
		total_len += len + 1;
	}

	str = malloc(sizeof(char) * total_len + 1);
	if (str == NULL)
		return (NULL);

	concat_str = str;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			*concat_str = av[i][j];
			concat_str++;
		}
		*concat_str = '\n';
		concat_str++;

	}
	*concat_str = '\0';

	return (str);
}
