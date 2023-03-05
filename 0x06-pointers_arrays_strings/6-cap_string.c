#include "main.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

/**
 * *cap_string - capitalizes all words of a string
 * @str: string to be capitalized
 *
 * Return: Always 0.
 */

char *cap_string(char *str)
{
	int i;
	int cap_next = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (cap_next && isalpha(str[i]))
		{
			str[i] = toupper(str[i]);
			cap_next = 0;
		}

		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
				str[i] == ',' || str[i] == ';' || str[i] == '.' ||
				str[i] == '!' || str[i] == '?' || str[i] == '"' ||
				str[i] == '(' || str[i] == ')' || str[i] == '{' ||
				str[i] == '}')
		{
			cap_next = 1;
		}
	}

	return (str);
}
