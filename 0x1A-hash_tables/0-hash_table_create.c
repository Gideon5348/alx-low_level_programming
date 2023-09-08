#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Create a hash table
 * @size: The size of the array (number of buckets)
 *
 * Return: A pointer to the newly created hash table, or NULL on failure.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table;
	unsigned long int i;

	/* Allocate memory for the entire hash table structure */
	new_table = malloc(sizeof(hash_table_t) + sizeof(hash_node_t *) * size);
	if (new_table == NULL)
		return (NULL);

	/* Initialize the size and array elements to NULL */
	new_table->size = size;
	new_table->array = (hash_node_t **)((char *)new_table + sizeof(hash_table_t));
	for (i = 0; i < size; i++)
		new_table->array[i] = NULL;

	return (new_table);
}
