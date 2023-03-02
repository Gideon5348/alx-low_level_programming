#include "main.h"
#include <string.h>

/* Declare _putchar function */
int _putchar(char c);

/**
 * puts2 - prints every other character of a string
 *
 * @str: string to be printed
 */

void puts2(char *str)
{
	int len, i;

	len = strlen(str);
	for (i = 0; i < len; i += 2)
		_putchar(str[i]);
	_putchar('\n');
}
