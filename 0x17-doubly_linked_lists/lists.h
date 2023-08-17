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
/* Function that returns the number of elements in a linked */
size_t dlistint_len(const dlistint_t *h);
/* Function that adds a new node at the beginning of a list */
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
/* Function that adds a new node at the end of a list */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
/* Function that frees a list */
void free_dlistint(dlistint_t *head);
/* Function that returns the nth node of a linked list */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
/* Function that returns the sum of all the data (n) of a linked list */
int sum_dlistint(dlistint_t *head);
/* Function that inserts a new node at a given position.*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);

#endif /* LISTS_H */
