#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string
 * @accept: string
 *
 * Return: Always 0.
 */

char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		char *p = accept;

		while (*p != '\0')
		{
			if (*s == *p)
			{
				return (s);
			}
			p++;
		}
		s++;
	}
	return (NULL);
}
