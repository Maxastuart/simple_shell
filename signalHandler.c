#include "header.h"

/**
 * signalHandler - signal handler for ctrl + c
 * @sig_num: signal number
 */

void signalHandler(int sig_num __attribute__((unused)))
{
	write(1, "\n", 1);
	type_prompt();
}
