#include "header.h"

/**
 * fork_fail - prints fork error message if fork fails
 *@pid_value: value of pid
 */

void fork_fail(int pid_value)
{
	write(STDOUT_FILENO, "fork failed with error code= ", 29);
	write(STDOUT_FILENO, _itoa(pid_value), _strlen(_itoa(pid_value)));
	write(STDOUT_FILENO, "\n", 2);
	write(STDERR_FILENO, "FORK error\n", 12);
}
