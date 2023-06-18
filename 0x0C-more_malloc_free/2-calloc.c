#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _calloc - allocates memory for an array and sets it to zero
 * @nmemb: number of elements in the array
 * @size: size of each element
 *
 * Return: a pointer to the allocated memory.
 * If nmemb or size is 0, then _calloc returns NULL
 * If malloc fails, then _calloc returns NULL
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int total_size;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total_size = nmemb * size;

	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);

	memset(ptr, 0, total_size);

	return (ptr);
}
