#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - oncatenates two strings
 *
 * @s1: String 1
 * @s2: String 2
 *
 * Return: Pointer to newly allocated space containing concatenated
 * strings or NULL on failure
 */

char *str_concat(char *s1, char *s2)
{
	char *concatenated_str;
	unsigned int len1 = 0, len2 = 0, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	concatenated_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concatenated_str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		concatenated_str[i] = s1[i];
	for (j = 0; j <= len2; j++)
		concatenated_str[i + j] = s2[j];

	return (concatenated_str);
}
