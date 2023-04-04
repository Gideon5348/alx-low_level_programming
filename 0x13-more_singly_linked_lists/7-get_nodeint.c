#include "lists.h"
#include <stdlib.h>

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @index: the index of the node, starting at 0.
 * @head: Pointer to head of list.
 *
 * Return: the nth node of a listint_t linked list
 * f the node does not exist, return NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current_node = head;
	unsigned int i = 0;

	while (current_node != NULL && i < index)
	{
		current_node = current_node->next;
		i++;
	}

	if (i == index && current_node != NULL)
		return (current_node);

	return (NULL);
}
