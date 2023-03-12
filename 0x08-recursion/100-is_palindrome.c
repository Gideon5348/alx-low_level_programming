#include "main.h"
#include <string.h>

int check_palindrome(char *s, int i, int len);
int _strlen_recursion(char *s);

/**
 * is_palindrome - returns 1 if a string is a palindrome and 0 if not
 * @s: string
 *
 * Return: 1 if palindrome or 0 if not.
 */

int is_palindrome(char *s)
{
	if (*s == 0)
		return (1);

	return (check_palindrome(s, 0, _strlen_recursion(s)));
}

/**
 * _strlen_recursion - length of a string
 * @s: string
 *
 * Return: length of a string
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * check_palindrome - recursively checks if a substring is aplindrome
 * @s: string
 * @i: iterator
 * @len: string length
 * Return: 1 if palindrome or 0 if not.
 */

int check_palindrome(char *s, int i, int len)
{
	if (*(s + i) != *(s + len - 1))
		return (0);
	if (i >= len)
		return (1);
	return (check_palindrome(s, i + 1, len - 1));
}
