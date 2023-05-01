#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Singly linked list node
 * @n: Integer stored in the node
 * @next: Pointer to the next node
 *
 * Description: A singly linked list node structure.
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* Function prototypes */
size_t print_listint(const listint_t *h);

#endif /* LISTS_H */

