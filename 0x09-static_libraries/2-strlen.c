#include "main.h"

/**
 * _strlen -  a function that returns the length of a string
 * @s: - length of string to be determined
 *
 * Return: Always 0.
 */

int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
