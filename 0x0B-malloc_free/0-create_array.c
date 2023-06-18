#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * create_array - creates an array of chars, and
 * initializes with a specific char.
 * @size: the size of the array.
 * @c: the char.
 *
 * Return: a pointer to the array, or NULL if it fails.
 * Returns NULL if size = 0
 */

char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int y;

	if (size == 0)
		return (NULL);

	array = malloc(sizeof(char) * size);

	if (array == NULL)
		return (NULL);

	for (y = 0; y < size; y++)
		array[y] = c;

	return (array);
}
