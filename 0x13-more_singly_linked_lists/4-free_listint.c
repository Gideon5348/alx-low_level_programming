#include "lists.h"
#include <stdlib.h>


/**
 * free_listint - frees a listint_t list.
 * @head: pointer to the head node of the list.
 *
 * Return: void.
 */

void free_listint(listint_t *head)
{
	listint_t *current_node;

	while (head)
	{
		current_node = head;
		head = head->next;
		free(current_node);
	}
}
