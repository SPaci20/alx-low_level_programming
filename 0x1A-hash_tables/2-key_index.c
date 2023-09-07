#include "hash_tables.h"

/**
 * key_index - Gets the index for a key in a hash table.
 * @key: The key to be hashed.
 * @size: The size of the array of the hash table.
 *
 * Return: The index at which the key/value pair should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

	if (key == NULL || size == 0)
		return (0);

	/* Calculate the hash value using the DJB2 hash function */
	hash_value = hash_djb2(key);

	/* Get the index by taking the remainder of the hash value */
	return (hash_value % size);
}
