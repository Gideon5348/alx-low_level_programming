#include "lists.h"

/**
 * free_listint - frees a listint_t list.
 * @head: pointer to the head of the list to free.
 */

void free_listint(listint_t *head)
{
	listint_t *current = NULL;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
