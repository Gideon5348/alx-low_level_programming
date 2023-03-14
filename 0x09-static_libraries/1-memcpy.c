#include "main.h"

/**
 * _memcpy -  copies memory area
 * @src: pointer to the source memory area
 * @dest: pointer to the destination memory area
 * @n: number of bytes to be copied
 *
 * Return: Always 0.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *ptr_dest = dest;
	char *ptr_src = src;

	while (n--)
	{
		*ptr_dest++ = *ptr_src++;
	}
	return (dest);
}
