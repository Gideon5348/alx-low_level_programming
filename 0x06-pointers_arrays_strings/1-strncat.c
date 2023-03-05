#include "main.h"
#include <string.h>

/**
 * *_strncat - concatenates two strings
 * @src: appends string to dest
 * @dest: returns a pointer to string
 * @n: bytes from src
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
