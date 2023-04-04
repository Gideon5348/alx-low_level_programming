#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @idx: the index of the list where the new node should be added.
 * @head: double pointer to the beginning of the linked list
 * @n: value to store in the new node.
 *
 * Return: the address of the new node, or NULL if it failed.
 * if it is not possible to add the new node at index idx,
 * do not add the new node and return NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current_node;
	unsigned int i;

	/* Create the new node and allocate memory*/
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	/* If the index is 0, insert node at the beginning */
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	/* Traverse the list until desired position is reached */
	current_node = *head;
	for (i = 0; i < idx - 1 && current_node != NULL; i++)
		current_node = current_node->next;

	/* If the desired position cannot be reached, return NULL */
	if (current_node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	 /* Insert the new node at the desired position */
	new_node->next = current_node->next;
	current_node->next = new_node;

	/* Returns the address of new node */
	return (new_node);
}
