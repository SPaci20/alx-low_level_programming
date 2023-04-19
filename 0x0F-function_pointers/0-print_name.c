#include <stdio.h>
#include "function_pointers.h"

/*
 * print_name - Prints a name
 * @name: name of the person
 * Return: Nothing
 * @f: function pointer
 */

void print_name(char *name, void(*f)(char *))
{
	if(name !=0  && f !=0)
		f(name);
}
