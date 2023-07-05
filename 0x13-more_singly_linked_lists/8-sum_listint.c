#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data in a listint_t list.
 * @head: a pointer to the head node of the list.
 *
 * Return: The sum of all the data (n) in the list.
 * if the list is empty, return 0.
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
