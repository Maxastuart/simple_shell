#include "header.h"

/**
 * write_not_found - error message if command does not exist
 * @input: string location of the shell as typed in
 * @count: number of how many child has been processed
 * @param: string of command to look for
 * Return: -1 error, 0 - malloc failed
 */
int write_nope(char *av, int count, char *param)
{
	char *str, *colon_space = ": ", *notfound = ": not found\n";

	str = malloc(sizeof(char) * 256);
	if (str == NULL)
		return (0);
	_strcpy(str, av);
	_strcat(str, colon_space);
	_strcat(str, count);
	_strcat(str, colon_space);
	_strcat(str, param);
	_strcat(str, notfound);

	write(STDOUT_FILENO, str, _strlen(str));
	free(str);
	return (-1);
}
