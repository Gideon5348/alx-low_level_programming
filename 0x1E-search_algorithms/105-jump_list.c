#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted list of integers using
 * the Jump search algorithm
 * @list: pointer to the head of the list to search in
 * @size: number of nodes in list
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located, or NULL if
 * value is not present or if head is NULL
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, prev, i;

	if (!list)
		return (NULL);

	step = sqrt(size);
	prev = 0;
	while (list->next && list->n < value)
	{
	printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
	prev = list->index;
	for (i = 0; list->next && i < step; ++i)
		list = list->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev, list->index);

	printf("Value checked at index [%lu] = [%d]\n", prev, list->n);
	while (list && prev < size && list->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		prev = list->index;
		list = list->next;
	}

	if (list && prev < size)
	printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);

	return (list && list->n == value ? list : NULL);
}

