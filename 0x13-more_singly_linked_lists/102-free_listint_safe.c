#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely
 * @h: Double pointer to the head of the list
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *next;

	if (h == NULL)
		return (0);

	current = *h;
	*h = NULL;

	while (current != NULL)
	{
		count++;
		next = current->next;
		free(current);
		if (next >= current)
			break;
		current = next;
	}

	return (count);
}
