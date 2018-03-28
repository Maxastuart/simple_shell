#include "header.h"

/**
 * _kill - kills process
 * @lineptr: string of stdin from read_cmd()
 */

void _kill(char *lineptr, char *tmp, char **tok)
{
	free(tmp);
	free(tok);
	free(lineptr);
	_exit(1);
}
