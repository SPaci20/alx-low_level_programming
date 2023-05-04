#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: the number to extract the bit from
 * @index: the index of the bit to extract
 * Return: the value of the bit at the given index, or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	/* Check if index is within the valid range */
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	/* Shift the bit to the rightmost position */
	n >>= index;

	/* Return the least significant bit */
	return (n & 1);
}
