#include "main.h"
#include <string.h>

/**
 * *_strncpy - copies a string
 * @dest: pointer to the destination
 * @src: poiter to the source string
 * @n: number of bytes to be copied
 *
 * Return: Always 0.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for ( ; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
