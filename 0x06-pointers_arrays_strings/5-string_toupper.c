#include "main.h"
#include <string.h>
#include <ctype.h>

/**
 * string_toupper -  changes all lowercase letters of a string to uppercase
 * @str: string to convert
 *
 * Return: Always 0.
 */

char *string_toupper(char *str)
{
	char *ptr = str;

	while (*ptr)
	{
		*ptr = toupper(*ptr);
		ptr++;
	}

	return (str);
}
