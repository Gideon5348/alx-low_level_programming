#include "lists.h"

/**
 * free_listint2 - frees a listint_t list.
 * @head: pointer to the pointer to the head node.
 */

void free_listint2(listint_t **head)
{
	listint_t *current;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		*head = (*head)->next;
		free(current);
		current = *head;
	}
}
