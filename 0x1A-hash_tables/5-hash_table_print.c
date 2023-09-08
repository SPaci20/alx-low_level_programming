#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key in a hash table.
 * @ht: The hash table.
 * @key: The key to look for.
 *
 * Return: The value associated with the key, or NULL if the key couldn't be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *current_node;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    /* Calculate the index where the key should be stored */
    index = key_index((unsigned char *)key, ht->size);

    /* Search for the key in the linked list at the calculated index */
    current_node = ht->array[index];
    while (current_node)
    {
        if (strcmp(current_node->key, key) == 0)
            return (current_node->value);
        current_node = current_node->next;
    }

    /* Key not found in the hash table */
    return (NULL);
}
