#include "search_algos.h"

/**
 * advanced_binary_recursive - Searches for a value in a
 *                        sorted array recursively.
 * @array: A pointer to the first element of the array.
 * @left: The starting index of the [sub]array to search.
 * @right: The ending index of the [sub]array to search.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 *
 * Description: Prints the [sub]array being searched after each change.
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid, i;

	if (left > right)
		return (-1);
	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return ((int)mid);

		return (advanced_binary_recursive(array, left, mid, value));
	}
	else if (array[mid] > value)
	{
		return (advanced_binary_recursive(array, left, mid - 1, value));
	}
	else
	{
		return (advanced_binary_recursive(array, mid + 1, right, value));
	}
}

/**
 * advanced_binary - Initiates the recursive binary search.
 * @array: A pointer to the first element of the array.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 *
 * Description: Handles edge cases and calls the recursive function.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (advanced_binary_recursive(array, 0, size - 1, value));
}
