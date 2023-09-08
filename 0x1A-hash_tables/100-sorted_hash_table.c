#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created sorted hash table,
 * or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht = malloc(sizeof(shash_table_t));

    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    memset(ht->array, 0, sizeof(shash_node_t *) * size);
    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

/**
 * shash_table_set - Inserts a key/value pair into a sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key.
 * @value: The value.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *new_node, *current, *prev = NULL;

    if (ht == NULL || key == NULL || value == NULL)
        return (0);

    current = ht->shead;

    while (current != NULL && strcmp(key, current->key) > 0)
    {
        prev = current;
        current = current->snext;
    }

    if (current != NULL && strcmp(key, current->key) == 0)
    {
        free(current->value);
        current->value = strdup(value);
        return (1);
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = NULL;

    if (prev == NULL)
    {
        new_node->snext = ht->shead;
        ht->shead = new_node;
    }
    else
    {
        prev->snext = new_node;
        new_node->snext = current;
    }

    if (current == NULL)
        ht->stail = new_node;

    return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key from a sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key to look for.
 *
 * Return: The value associated with the key, or NULL if the key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *node;

    if (ht == NULL || key == NULL)
        return (NULL);

    index = key_index((unsigned char *)key, ht->size);

    node = ht->array[index];

    while (node)
    {
        if (strcmp(node->key, key) == 0)
            return (node->value);
        node = node->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
    int first = 1; /* Flag to check if it's the first key-value pair */
    shash_node_t *node;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->shead;

    while (node != NULL)
    {
        if (first)
            first = 0;
        else
            printf(", ");

        printf("'%s': '%s'", node->key, node->value);
        node = node->snext;
    }

    printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: The sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    int first = 1; /* Flag to check if it's the first key-value pair */
    shash_node_t *node;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->stail;

    while (node != NULL)
    {
        if (first)
            first = 0;
        else
            printf(", ");

        printf("'%s': '%s'", node->key, node->value);
        node = node->sprev;
    }

    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *node, *next;

    if (ht == NULL)
        return;

    node = ht->shead;

    while (node != NULL)
    {
        next = node->snext;
        free(node->key);
        free(node->value);
        free(node);
        node = next;
    }

    free(ht->array);
    free(ht);
}

