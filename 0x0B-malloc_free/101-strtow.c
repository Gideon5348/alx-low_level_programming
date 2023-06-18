#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * count_words - counts the number of words in a string.
 * @str: the input string.
 *
 * Return: number of words.
 */
int count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
		i++;
	}

	return count;
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: Pointer to an array of strings (words), or NULL if it fails.
 */
char **strtow(char *str)
{
	int i, j, k, len, words;
	char **words_arr;
	char *word;

	if (str == NULL || *str == '\0')
		return NULL;

	words = count_words(str);
	if (words == 0)
		return NULL;

	words_arr = malloc((words + 1) * sizeof(char *));
	if (words_arr == NULL)
		return NULL;

	i = 0;
	while (*str != '\0')
	{
		while (*str == ' ')
			str++;

		len = 0;
		while (str[len] != ' ' && str[len] != '\0')
			len++;

		word = malloc((len + 1) * sizeof(char));
		if (word == NULL)
		{
			for (k = 0; k < i; k++)
				free(words_arr[k]);
			free(words_arr);
			return NULL;
		}

		for (j = 0; j < len; j++)
			word[j] = str[j];
		word[j] = '\0';
		words_arr[i] = word;
		i++;

		str += len;
	}

	words_arr[i] = NULL;
	return words_arr;
}
