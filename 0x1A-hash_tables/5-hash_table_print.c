#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - Print a hash table
 * @ht: The hash table to print
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0;
	int first = 1;  /* Flag to track if it's the first key-value pair */

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		hash_node_t *current = ht->array[i];

		while (current != NULL)
		{
			if (!first)
				printf(", ");  /* Print a comma and space between key-value pairs */
			printf("'%s': '%s'", current->key, current->value);
			first = 0;
			current = current->next;
		}
	}
	printf("}\n");
}
