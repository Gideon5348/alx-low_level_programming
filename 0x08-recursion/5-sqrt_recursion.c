#include "main.h"

int sqrt_helper(int n, int s, int e);

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
	else if (n == 0 || n == 1)
		return (n);
	else
		return (sqrt_helper(n, 1, n));
}

/**
 * sqrt_helper - recursive helper function to calculate square root.
 * @n: The number to calculate the square root of.
 * @s: The starting point for the search.
 * @e: The ending point for the search.
 *
 * Return: the natural square root of a number.
 *  If n does not have a natural square root, the function should return -1
 */

int sqrt_helper(int n, int s, int e)
{
	int mid = (s + e) / 2;

	if (mid * mid == n)
		return (mid);
	else if (s >= e)
		return (-1);
	else if (mid * mid > n)
		return (sqrt_helper(n, s, mid - 1));
	else
		return (sqrt_helper(n, mid + 1, e));
}
