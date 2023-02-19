#include <stdio.h>
/* main - A program that prints the size of various types on the computer it is compiled and run on
 *
 * Return:0 (Success)
 */
int main (void)
{
	int integerType;
	float floatType;
	double doubleType;
	char charType;

	/*Size of the various type on the computer*/
	Printf("Size of int: %ld bytes\n",sizeof(integerType));
	printf("Size of float: %ld bytes\n",sizeof(floatType));
	printf("Size of double: %ld bytes\n",sizeof(doubleType));
	printf("Size of char: %ls bytes\n",sizeof(charType));

	return(0);
}

