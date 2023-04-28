#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: Pointer to the head of the list
 *
 * Description: This function frees a linked list by iterating through it and
 *              freeing the memory allocated for each node and its string.
 */

void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}
