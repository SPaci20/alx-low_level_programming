#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data of a listint_t linked list.
 * @head: A pointer to the head of the linked list.
 * Return: The sum of all the data (n) of the linked list.
 *         If the linked list is empty, return 0.
 */
int sum_listint(listint_t *head)
{
	listint_t *current = head;
	int sum = 0;

	while (current != NULL)
	{

		sum += current->n;
		current = current->next;
	}

	return (sum);
}
