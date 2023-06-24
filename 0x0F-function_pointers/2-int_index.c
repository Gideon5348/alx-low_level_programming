#include "function_pointers.h"

/**
 * int_index - searches for an integer.
 * @array: array.
 * @size: size of elements in array.
 * @cmp: pointer to the function to be used to compare values.
 * Return: index of first element for which cmp function does not return 0.
 * If no element matches, return -1
 * If size <= 0, return -1
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	if (array != NULL && cmp != NULL && size > 0)
	{
		int y;

		for (y = 0; y < size; y++)
		{
			if (cmp(array[y]) != 0)
				return (y);
		}
	}

	return (-1);
}
