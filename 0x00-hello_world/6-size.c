#include <stdio.h>
/*
 * main - Entry point
 *
 * Description: 'A program that prints the size of various types'
 *
 * Return:0 (Success)
 */
int main(void)
{
	int integerType;
	float floatType;
	char charType;
	long longintType;
	long longlongintType;

	/*Size of the various type on the computer*/
	Printf("Size of int: %ld bytes\n", sizeof(integerType));
	printf("Size of float: %ld bytes\n", sizeof(floatType));
	printf("Size of char: %ld bytes\n", sizeof(charType));
	printf("Size of long: %ld bytes\n", sizeof(longintType));
	printf("Size of long: %ld bytes\n", sizeof(longlongintType));

	return (0);
}

