#include "main.h"
#include <string.h>

/* Declare _putchar function */
int _putchar(char c);

/**
 * puts_half - a function that prints half of a string, followed by a new line
 *
 * @str: half of string to be printed
 */

void puts_half(char *str)
{
	int len = strlen(str);
	int half_len = len / 2;
	int n;
	int i;

	if (len % 2 == 0)
	{
		n = half_len;
	}
	else
	{
		n = half_len + 1;
	}


	for (i = n; i < len; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
