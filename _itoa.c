#include "header.h"

/**
 * _itoa - converts int to string
 * @n: interger to convert
 *
 * Return: string of numbers
 */
char *_itoa(int n)
{
	int copy, i = 0;
	char *str;

	copy = n;

	while (n != 0)
	{
		i++;
		n = n / 10;
	}

	str = malloc(i * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	i--;

	while (i >= 0)
	{
		str[i] = copy % 10 + '0';
		copy = copy / 10;
		i--;
	}

	return (str);
}
