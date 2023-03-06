#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: memory area
 * @n: bytes of the memory area pointed to by s
 * @b: constant byte
 *
 * Return: Always 0.
 */

char *_memset(char *s, char b, unsigned int n)
{
	char *ptr = s;

	while (n--)
	{
		*ptr++ = b;
	}
	return (s);
}
