#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list
 * @head: Pointer to the head node of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current, *loop;

	current = head;
	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;
		if (current > current->next)
			loop = current->next;
		else
			loop = NULL;
		current = current->next;
		if (current == loop)
		{
			printf("-> [%p] %d\n", (void *)current, current->n);
			count++;
			break;
		}
	}

	return (count);
}
