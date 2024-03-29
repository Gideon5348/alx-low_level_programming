#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - prints a name.
 * @name: name of the person.
 * @f: pointer to function
 *
 * Return: nothing.
 */

void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}
