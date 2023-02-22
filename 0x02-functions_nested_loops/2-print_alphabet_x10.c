#include "main.h"

/**
 * print_alphabet_x10 - prints 10 times the alphabet, in lowercase.
 */
void print_alphabet_x10(void)
{
	char ll;
	int i;

	i = 0;

	while (i < 10)
	{
		ll = 'a';
		while (ll <= 'z')
		{
			_putchar(ll);
			ll++;
		}
		_putchar('\n');
		i++
	}
}
