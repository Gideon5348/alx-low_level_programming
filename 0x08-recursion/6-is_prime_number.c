#include "main.h"

int check_prime(int n, int y);


/**
 * is_prime_number - returns 1 if the input integer is a prime number.
 * @n: the number
 *
 * Return: 1 if the input integer is a prime number, otherwise return 0.
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (check_prime(n, n - 1));
}

/**
 * check_prime - calculates if a number is prime recursively.
 * @n: the number to check.
 * @y: iterator
 *
 * Return: 1 if the input integer is a prime number, otherwise return 0.
 */

int check_prime(int n, int y)
{
	if (y == 1)
		return (1);

	if (n % y == 0 && y > 0)
		return (0);

	return (check_prime(n, y - 1));
}
