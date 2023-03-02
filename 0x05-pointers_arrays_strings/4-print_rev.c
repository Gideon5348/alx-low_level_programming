#include "main.h"

/* Declare _putchar function */
int _putchar(char c);

/**
 * print_rev -  prints a string, in reverse, followed by a new line
 * @s: string to be printed in reverse
 *
 * Return: Always 0.
 */

void print_rev(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	for (i = i - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
