#include "header.h"

/**
 * location_check - looks if cmd exists in current directory
 * @cmd: takes command
 *
 * Return: 0 if found, otherwise 1
 */
int location_check(char *cmd)
{
	return (access(cmd, F_OK));
}
