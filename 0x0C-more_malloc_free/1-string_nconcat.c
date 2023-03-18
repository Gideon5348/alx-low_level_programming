#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * string_nconcat - Concatenates two strings
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes of s2 to be concatenated
 *
 * Return: Pointer to newly allocated space in memory
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat_str;
	unsigned int len1 = 0, len2 = 0, i = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;

	while (s2[len2] != '\0')
		len2++;

	if (n >= len2)
		n = len2;

	concat_str = malloc(sizeof(char) * (len1 + n + 1));

	if (concat_str == NULL)
		return (NULL);

	while (*s1 != '\0')
		concat_str[i++] = *s1++;

	i = 0;

	while (i < n)
		concat_str[len1++] = s2[i++];

	concat_str[len1] = '\0';

	return (concat_str);
}
