#include "main.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * _calloc - allocates memory for an array
 * @nmemb: Number of elements in the array
 * @size: Size of each element in bytes
 *
 * Return: A pointer to the allocated memory, or NULL if it fails
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);

	memset(ptr, 0, nmemb * size);

	return (ptr);
}
