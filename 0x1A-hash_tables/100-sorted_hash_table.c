#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_tables.h"

/**
 * shash_table_create - Create a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the created shash_table_t, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = NULL;

	if (size < 1)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
	return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Insert a key-value pair into the sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key to insert.
 * @value: The value to insert.
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node = NULL, *temp = NULL;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp)
	{
	if (strcmp(temp->key, key) == 0)
	{
		free(temp->value);
		temp->value = strdup(value);
		if (temp->value == NULL)
			return (0);
		return (1);
	}
	temp = temp->next;
	}

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (0);

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
	return (0);
	}

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (0);
	}
	node->next = ht->array[index];
	ht->array[index] = node;
	if (ht->shead == NULL || strcmp(key, ht->shead->key) < 0)
	{
		node->snext = ht->shead;
		node->sprev = NULL;
		if (ht->shead)
			ht->shead->sprev = node;
	ht->shead = node;
	}
	else
	{
		temp = ht->shead;
		while (temp->snext && strcmp(key, temp->snext->key) > 0)
			temp = temp->snext;
		node->sprev = temp;
		node->snext = temp->snext;
		if (temp->snext)
		temp->snext->sprev = node;
		temp->snext = node;
	}
	if (ht->stail == NULL || strcmp(key, ht->stail->key) > 0)
	ht->stail = node;
	return (1);
}

/**
 * shash_table_get - Retrieve a value associated with a key from the sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key to search for.
 *
 * Return: The value associated with the key, or NULL if not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *temp = NULL;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
	temp = temp->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Print the sorted hash table.
 * @ht: The sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp = NULL;
	int first = 1;

	if (ht == NULL)
	return;

	printf("{");
	temp = ht->shead;

	while (temp)
	{
		if (first)
			first = 0;
		else
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		temp = temp->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - Print the sorted hash table in reverse order.
 * @ht: The sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp = NULL;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
 	temp = ht->stail;

	while (temp)
	{
		if (first)
		first = 0;
	else
		printf(", ");
	printf("'%s': '%s'", temp->key, temp->value);
	temp = temp->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - Delete the entire sorted hash table.
 * @ht: The sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *node = NULL, *next = NULL;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			next = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = next;
		}
	}

	free(ht->array);
	free(ht);
}
