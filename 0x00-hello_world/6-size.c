#include <stdio.h>
/**
 * main - A program that prints the size of various types
 *
 * Return: 0 (Success)
 */
int main(void)
{
	char a;
	int b;
	long int c;
	long long int d;
	float f;

printf("Size of a char: %lu byte(s)\n", (unsigned long)Sizeof(a));
printf("Size of a int: %lu byte(s)\n", (unsigned long)Sizeof(b));
printf("Size of a long int: %lu byte(s)\n", (unsigned long)Sizeof(c));
printf("Size of a long long int: %lu byte(s)\n", (unsigned long)Sizeof(d));
printf("Size of a float: %lu byte(s)\n", (unsigned long)Sizeof(f));
	return (0);
}
