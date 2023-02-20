#include <stdio.h>

/**
 * main - prints the alphabet in lowercase and then in uppercase.
 *
 * Return: Always 0.
 */
int main(void)
{
	char ll;

	for (ll = 'a'; ll <= 'z'; ll++)
		putchar(ll);

	for (ll = 'A'; ll <= 'Z'; ll++)
		putchar(ll);

	putchar('\n');

	return (0);
}
