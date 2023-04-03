#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints all the elements of a list_t list.
 * @h: pointer to head node
 *
 * Return: the number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("[%d] %s\n", h->len, h->str != NULL ? h->str : "(nil)");
		h = h->next;
		count++;
	}

	return (count);
}
