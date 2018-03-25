#include "header.h"

/**
 * write_nope - writes commmand or director not found to stdout, or error
 *
 * Return: Always -1.
 */
int write_nope(void)
{
	char *nope = "command or directory not found\n",
		*error = "There was an error writing to standard out\n";

	if (write(STDOUT_FILENO, nope, 32) != 32)
		write(STDERR_FILENO, error, 44);
	return (-1);
}
