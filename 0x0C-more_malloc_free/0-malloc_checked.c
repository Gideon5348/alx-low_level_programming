#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * malloc_checked - allocates memory using malloc.
 * @b: the number of bytes to allocate.
 *
 * Return: pointer to the allocated memory.
 * if malloc fails, the malloc_checked function should cause
 * normal process termination with a status value of 98
 */

void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
		printf("Error: malloc failed\n");
		exit(98);
	}

	return (ptr);
}
