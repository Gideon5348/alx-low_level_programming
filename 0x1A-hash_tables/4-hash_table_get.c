#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_get - Retrieve a value associated with a key from the hash table
 * @ht: The hash table to look into
 * @key: The key to search for
 *
 * Return: The value associated with the key, or NULL if not found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	/* Calculate the index where the key/value pair should be located */
	index = key_index((const unsigned char *)key, ht->size);

	/* Traverse the linked list at the computed index */
	current = ht->array[index];
	while (current != NULL)
	{
	/* If the key is found, return the associated value */
	if (strcmp(current->key, key) == 0)
	{
		return (current->value);
	}
	current = current->next;
	}

	/* Key was not found in the linked list */
	return (NULL);
}
