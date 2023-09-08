#include <stdlib.h>
#include "hash_tables.h"

/**
 * key_index - Get the index of a key in the hash table array.
 * @key: The key to be hashed.
 * @size: The size of the array of the hash table.
 *
 * Return: The index at which the key/value pair should be stored
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

	/* Compute the hash value using the hash_djb2 function */
	hash_value = hash_djb2(key);

	/* Calculates index by taking the remainder of hash value and size */
	return (hash_value % size);
}
