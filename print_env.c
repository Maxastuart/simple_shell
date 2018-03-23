#include "header.h"

/**
 * env - Implement the env built-in, that prints the current environment
 */

void env(void)
{
	char **paths, *path;
	int i = 0, j = 0;


	while(environ[i])
	{
		path = environ[i];
		while (path[j])
		{
			j++;
		}
		write(STDOUT_FILENO, path, j);
		write(STDOUT_FILENO, "\n", 1);
		j = 0;
		i++;
	}
	exit(1);
}
