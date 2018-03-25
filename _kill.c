#include "header.h"

/**
 * _kill - kills process
 * @lineptr: string of stdin from read_cmd()
 */

void _kill(char *lineptr)
{
	free(lineptr);
	_exit(1);
}
