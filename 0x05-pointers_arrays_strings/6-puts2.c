#include "main.h"

/* Declare _putchar function */
int _putchar(char c);

/**
 * puts2 - prints every other character of a string
 *
 * @str: string to be printed
 */

void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i += 2)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
