#include "main.h"

/**
 * wildcmp - Compares two strings.
 * @s1: the first string.
 * @s2: the second string.
 *
 * Return: 1 if the strings can be considered identical, otherwise return 0.
 */

int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1);

		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);

		return (wildcmp(s1, s2 + 1));
	}

	if (*s1 != *s2)
		return (0);

	if (*s1 == '\0')
		return (1);

	return (wildcmp(s1 + 1, s2 + 1));
}
