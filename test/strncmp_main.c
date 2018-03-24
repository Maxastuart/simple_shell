#include "header.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	char s1[] = "Hello";
	char s2[] = "H World!";
	int n = 3;

	printf("%d\n", _strncmp(s1, s2, n));
	printf("%d\n", _strncmp(s2, s1, n));
	printf("%d\n", _strncmp(s1, s1, n));
	return (0);
}
