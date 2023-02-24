#include "main.h"

/*
 * more_numbers - prints 10 times the numbers, from 0 to 14
 *
 * Return: void
 */

void more_numbers(void);

/**
 * more_numbers - prints 10 times the numbers, from 0 to 14
 *
 * Return: void
 */

void more_numbers(void)
{
	int count;
	int i;

	for (count = 0; i < 10; count++)
	{
		for (i = 0; i < 15; i++)
		{
		if (i >= 10)
		{
		_putchar(i/10 + '0');
		}
	_putchar(i%10 + '0');
		}
	_putchar('\n');
	}
}
