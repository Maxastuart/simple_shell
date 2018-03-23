#include "header.h"

/**
 * _kill - kills process
 */

void _kill(void)
{
	kill (getppid(), 2);
	_exit(1);
}
