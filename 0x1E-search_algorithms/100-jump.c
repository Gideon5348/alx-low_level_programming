#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers
 * using the Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: the first index where value is located, or -1 if not found
 */

int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t prev = 0;
	size_t i;

	if (array == NULL)
		return (-1);

	while (array[prev] < value)
	{
	printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);

	if (prev + step < size)
		prev += step;
	else
		break;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev - step, prev);

	for (i = prev - step; i <= prev && i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);

		if (array[i] == value)
			return ((int)i);
	}

	return (-1);
}

