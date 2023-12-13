#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers using
 * the Jump search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found
 * or if the array is NULL.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t left = 0, right = 0;
	size_t i;

	if (array == NULL)
	{
		return (-1); /* Return -1 if the array is NULL */
	}
	while (right < size && array[right] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", right, array[right]);
		left = right;
		right += step;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", left, right);
	for (i = left; i < size && i <= right; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);

		if (array[i] == value)
		{
			return (i); /* Return the index if the value is found */
		}
	}
	return (-1); /* Return -1 if the value is not found in the array */
}
