#include <stddef.h>
#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data (n)
 * in a dlistint_t linked list.
 * @head: Pointer to the head of the doubly linked list.
 * Return: Sum of the data in the list, or 0 if the list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
