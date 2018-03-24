#include "header.h"

/**
 * _strcmp - compares one string to another, 1 array element at a time
 * @s1: character pointer to the first string array
 * @s2: character pointer to the second string array
 *
 * Return: an integer, positive if s1 > s2, negative if s1 < s2, 0 if equal.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
		i++;

	return (s1[i] - s2[i]);
}
