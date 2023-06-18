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
	int flag, count, words;

	flag = 0;
	words = 0;

	for (count = 0; str[count] != '\0'; count++)
	{
		if (str[count] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			words++;
		}
	}

	return (words);
}

/**
 * allocate_matrix - allocates memory for the matrix
 * @total_words: total number of words
 *
 * Return: pointer to allocated matrix
 */
char **allocate_matrix(int total_words)
{
	char **matrix;

	matrix = (char **)malloc(sizeof(char *) * (total_words + 1));
	if (matrix == NULL)
		return (NULL);

	return (matrix);
}

/**
 * extract_word - extracts a word from the string
 * @str: string to extract word from
 * @start: starting index of the word
 * @end: ending index of the word
 *
 * Return: pointer to the extracted word
 */
char *extract_word(char *str, int start, int end)
{
	char *word, *tmp;
	int count;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (word == NULL)
		return (NULL);

	tmp = word;
	for (count = start; count < end; count++)
		*tmp++ = str[count];
	*tmp = '\0';

	return (word);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 *         or NULL (Error)
 */

char **strtow(char *str)
{
	char **matrix, *tmp;
	int i, word_count = 0, len = 0, total_words, char_count = 0, start, end;

	if (str == NULL || *str == '\0')
		return (NULL);

	while (str[len] != '\0')
		len++;
	total_words = count_words(str);
	if (total_words == 0)
		return (NULL);

	matrix = allocate_matrix(total_words);
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (char_count)
			{
				end = i;
				tmp = extract_word(str, start, end);
				if (tmp == NULL)
					return (NULL);
				matrix[word_count] = tmp;
				word_count++;
				char_count = 0;
			}
		}
		else if (char_count++ == 0)
			start = i;
	}

	matrix[word_count] = NULL;

	return (matrix);
}
