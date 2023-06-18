#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - function returns a pointer to a new string
 * which is a duplicate of the string str.
 * @str: the string to duplicate
 *
 * Return: a pointer to a new string which is a duplicate of the string str.
 * Returns NULL if str = NULL
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int len = 0;
	unsigned int y;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	duplicate = malloc((len + 1) * sizeof(char));

	if (duplicate == NULL)
		return (NULL);

	for (y = 0; y <= len; y++)
		duplicate[y] = str[y];

	return (duplicate);
}
