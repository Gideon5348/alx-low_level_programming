#include "main.h"
#include <string.h>

/**
 * *_strcat - concatenates two strings.
 * @src: string appends to dest string
 * @dest: string
 *
 * Return: Always 0.
 */

char *_strcat(char *dest, char *src)
{
	char *ptr = dest + strlen(dest);

	while (*src != '\0')
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';

	return (dest);
}
