#include "main.h"

/**
 * _print_rev_recursion - function that prints a string in reverse
 *
 * @s: string to receive
 */

void print_reverse_recursion(char *s)
{
    if (*s == '\0')
    {
        return;
    }
    print_reverse_recursion(s + 1);
    _putchar(*s);
}
