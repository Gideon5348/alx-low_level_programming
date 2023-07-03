#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything.
 * @format: list of types of arguments passed to the function.
 *
 * Return: Nothing.
 */

void print_all(const char * const format, ...)
{
	unsigned int i = 0;
	char *str;
	char curr_format;
	va_list args;

	va_start(args, format);

	while (format && format[i])
	{
		curr_format = format[i];

		if (curr_format == 'c')
			printf("%c", va_arg(args, int));
		else if (curr_format == 'i')
			printf("%d", va_arg(args, int));
		else if (curr_format == 'f')
			printf("%f", va_arg(args, double));
		else if (curr_format == 's')
		{
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(nil)";
			printf("%s", str);
		}

		if (format[i + 1] != '\0' &&
				(curr_format == 'c' || curr_format == 'i' ||
				 curr_format == 'f' || curr_format == 's'))
			printf(", ");

		i++;
	}

	printf("\n");

	va_end(args);
}
