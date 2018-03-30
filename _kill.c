#include "header.h"

/**
 * _kill - kills process
 * @lineptr: string of stdin from read_cmd()
 * @tmp: temporary string from read_cmd()
 * @tok: token from read_cmd()
 */

void _kill(char *lineptr, char *tmp, char **tok)
{
	free(tmp);
	free(tok);
	free(lineptr);
	_exit(0);
}
