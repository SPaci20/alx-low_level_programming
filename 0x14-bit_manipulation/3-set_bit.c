#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: a pointer to the number to set the bit in
 * @index: the index of the bit to set
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	/* Check if index is within the valid range */
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	/* Set the bit to 1 using a bitwise OR operation */
	*n |= (1 << index);

	return (1);
}
