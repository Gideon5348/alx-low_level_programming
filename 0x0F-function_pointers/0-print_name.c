#include "function_pointers.h"
#include <stddef.h>

/**
 * print_name - prints a name
 * @name: string
 * @f: function pointer
 *
 * Return: Void.
 */

void print_name(char *name, void (*f)(char *))
{
	f(name);
}
