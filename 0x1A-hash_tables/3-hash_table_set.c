#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - Add or update a key/value pair in the hash table
 * @ht: The hash table to which the key/value pair will be added or updated
 * @key: The key to be added or updated
 * @value: The value to be associated with the key
 *
 * Return: 1 if successful, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *current;

	if (ht == NULL || key == NULL || value == NULL || *key == '\0')
		return (0);

	/* Calculate the index where the key/value pair should be stored */
	index = key_index((const unsigned char *)key, ht->size);

	/* Check for collisions by iterating through the l-list at index */
	current = ht->array[index];
	while (current != NULL)
	{
		/* If the key already exists, update its value and return */
	if (strcmp(current->key, key) == 0)
	{
		free(current->value);  /* Free the existing value */
		current->value = strdup(value);
			/* Duplicate and store the new value */
		if (current->value == NULL)
			return (0);
		return (1);
	}
	current = current->next;
	}
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);      /* Duplicate the key */
	new_node->value = strdup(value);  /* Duplicate the value */
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
