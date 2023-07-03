#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - function that prints strings, followed by a new line.
 * @separator: string to be printed between the strings
 * @n: number of strings passed to the function.
 * @...: variable number of arguments.
 *
 * Return: nothing.
 * If separator is NULL, don’t print it
 * If one of the string is NULL, print (nil) instead.
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	char *str;
	unsigned int i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);

		if (str != NULL)
			printf("%s", str);
		else
			printf("(nil)");

		if (separator != NULL && i != n - 1)
			printf("%s", separator);
	}

	printf("\n");

	va_end(args);
}
