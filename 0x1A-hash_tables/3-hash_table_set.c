#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table.
 * @key: The key (cannot be an empty string).
 * @value: The value associated with the key (can be an empty string).
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *current_node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	/* Calculate the index where the key should be stored */
	index = key_index((unsigned char *)key, ht->size);

	/* Check if the key already exists; if so, update its value */
	current_node = ht->array[index];
	while (current_node)
	{
		if (strcmp(current_node->key, key) == 0)
		{
			/* Free the existing value and update it with the new value */
			free(current_node->value);
			current_node->value = strdup(value);
			if (current_node->value == NULL)
				return (0);
			return (1);
		}
		current_node = current_node->next;
	}
	/* If the key doesn't exist, create a new node and add it to the list */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);

	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}
	/* Insert the new node at the beginning of the list at the index */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
