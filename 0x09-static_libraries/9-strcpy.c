#include "main.h"
#include <stdio.h>

/**
 * *_strcpy - copies the string pointed to by src
 *
 *@src: string
 *@dest: string
 *
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	char *p = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (p);
}
