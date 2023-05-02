#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: Double pointer to the head of the list.
 * Return: The size of the list that was free'd.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *temp;

	if (!h)
		return (0);

	current = *h;
	while (current)
	{
		count++;
		if (current > current->next)
		{
			printf("Freeing [%p] %d\n", (void *)current, current->n);
			temp = current->next;
			free(current);
			current = temp;
		}
		else
		{
			printf("Freeing [%p] %d\n", (void *)current, current->n);
			free(current);
			*h = NULL;

			return (count);
		}
	}

	*h = NULL;
	return (count);
}
