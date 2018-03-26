#include "header.h"

/**
 * write_nope - error message if command does not exist
 * @av: string location of the shell as typed in
 * @count: number of how many child has been processed
 * @param: string of command to look for
 *
 * Return: -1 error, 0 - malloc failed
 */
int write_nope(char *av, int count, char *param)
{
	char *str, *colon_space = ": ", *notfound = ": not found\n";
	char *cnt = _itoa(count);
	char *error = "There was an error writing to standard out\n";
	int len;

	str = malloc(sizeof(char) * 256);
	if (str == NULL)
		return (0);
	_strcpy(str, av);
	_strcat(str, colon_space);
	_strcat(str, cnt);
	_strcat(str, colon_space);
	_strcat(str, param);
	_strcat(str, notfound);
	len = _strlen(str);

	if (write(STDOUT_FILENO, str, len) != len)
		write(STDERR_FILENO, error, 44);
	free(str);

	return (-1);
}
