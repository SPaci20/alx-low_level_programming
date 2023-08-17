#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/* Structure for a doubly linked list node */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;

/* Function prototype for printing a doubly linked list */
size_t print_dlistint(const dlistint_t *h);
/*function that returns the number of elements in a linked */
size_t dlistint_len(const dlistint_t *h);

#endif /* LISTS_H */

