#include "main.h"
#include <string.h>

int check_palindrome(char *s, int start, int end);

/**
 * is_palindrome -  returns 1 if a string is a palindrome.
 * @s: string
 *
 * Return: 1 if a string is a palindrome and 0 if not.
 */

int is_palindrome(char *s)
{
	int len = strlen(s);

	return (check_palindrome(s, 0, len - 1));
}

/**
 * check_palindrome - Recursive helper function to check for string palindrome.
 * @s: string
 * @start: start of comparison.
 * @end: end of comparison.
 *
 * Return: 1 if a string is a palindrome and 0 if not.
 */

int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (check_palindrome(s, start + 1, end - 1));
}
