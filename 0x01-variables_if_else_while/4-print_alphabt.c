#include <stdio.h>

/**
 * main - A program that prints the alphabet in lowercase except q and e.
 *
 * Return: Always 0.
 */
int main(void)
{
	char ll;

	for (ll = 'a'; ll <= 'z'; ll++)
	{
		if (ll != 'e' && ll != 'q')
			putchar(ll);
	}

	putchar('\n');

	return (0);
}
