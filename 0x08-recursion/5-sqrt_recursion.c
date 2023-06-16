#include "main.h"

int sqrt_helper(int n, int i);

/**
 * _sqrt_recursion -  returns the natural square root of a number.
 * @n: number to calculate square root of.
 *
 * Return: the natural square root of a number.
 * If n does not have a natural square root, the function should return -1
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (sqrt_helper(n, 0));
}

/**
 * sqrt_helper - recursive helper function to calculate square root.
 * @n: The number to calculate the square root of.
 * @i: The current value being checked for square root.
 *
 * Return: the natural square root of a number.
 *  If n does not have a natural square root, the function should return -1
 */

int sqrt_helper(int n, int i)
{
	if (i * i > n)
		return (-1);

	if (i * i == n)
		return (i);

	return (sqrt_helper(n, i + 1));
}
