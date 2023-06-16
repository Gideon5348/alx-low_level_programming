#include "main.h"

/**
 * _sqrt_recursion -  returns the natural square root of a number.
 * @n: number to calculate square root of.
 *
 * Return: the natural square root of a number.
 * If n does not have a natural square root, the function should return -1
 */

int _sqrt_recursion(int n);
int sqrt_helper(int n, int guess);

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0 || n == 1)
		return (n);
	else
		return (sqrt_helper(n, n / 2));
}

/**
 * sqrt_helper - recursive helper function to calculate square root.
 * @n: The number to calculate the square root of
 * @guess: The current guess for the square root
 *
 * Return: the natural square root of a number.
 *  If n does not have a natural square root, the function should return -1
 */

int sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	else if (guess == 0 || guess == 1)
		return (-1);
	else
		return (sqrt_helper(n, guess - 1));
}
