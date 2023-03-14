#include "main.h"
#include <string.h>

/**
 * *_strncat - concatenates two strings
 * @src: pointer to the source string
 * @dest: pointer to the destination string
 * @n: bytes to be copied
 *
 * Return: Always 0.
 */

char *_strncat(char *dest, char *src, int n)
{
	int dest_len = strlen(dest);
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';

	return (dest);
}
