#include "header.h"

/**
 * _strncmp - compares n characters of one string to another
 * @s1: character pointer to the first string array
 * @s2: character pointer to the second string array
 * @n: the number of characters to check
 *
 * Return: an integer, positive if s1 > s2, negative if s1 < s2, 0 if equal.
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while ((s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0')) && i < n)
		i++;

	if (n == i)
		i--;

	return (s1[i] - s2[i]);
}
