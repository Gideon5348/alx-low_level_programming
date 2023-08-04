#include <stdio.h>
#include "main.h"

/**
 * flip_bits - number of bits needed to flip to get from one number to another.
 * @n: the first number.
 * @m: the second number.
 *
 * Return: the number of bits needed to flip.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;

	while (xor_result > 0)
	{
		if (xor_result & 1)
			count++;
		xor_result >>= 1;
	}

	return (count);
}
