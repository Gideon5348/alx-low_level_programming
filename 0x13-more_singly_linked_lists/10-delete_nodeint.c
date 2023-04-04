#include "lists.h"
#include "stdlib.h"

/**
 * delete_nodeint_at_index - deletes the node at index of a linked list.
 * @index:  the index of the node that should be deleted.
 * @head: A pointer to a pointer to the head node of the linked list.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current_node, *prev;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		current_node = *head;
		*head = (*head)->next;
		free(current_node);
		return (1);
	}

	prev = *head;
	current_node = (*head)->next;
	for (i = 1; current_node != NULL && i < index; i++)
	{
		prev = current_node;
		current_node = current_node->next;
	}

	if (current_node == NULL)
		return (-1);

	prev->next = current_node->next;
	free(current_node);

	return (1);
}
