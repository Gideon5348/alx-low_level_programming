#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at the given index of a list.
 * @head: double pointer to the head of the linked list.
 * @index: index of the node to delete.
 * Return: 1 if successful, -1 if failed.
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
	return (-1);

	if (index == 0)
	{
		*head = current->next;
		if (*head)
		(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (current && i < index)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
	return (-1);

	if (current->prev)
	current->prev->next = current->next;

	if (current->next)
	current->next->prev = current->prev;

	free(current);
	return (1);
}
