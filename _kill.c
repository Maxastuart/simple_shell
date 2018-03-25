#include "header.h"

/**
 * _kill - kills process
 */

void _kill(char *lineptr)
{
	free(lineptr);
	_exit(1);
}
