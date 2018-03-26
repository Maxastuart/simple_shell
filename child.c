#include "header.h"

/**
 * child_exec - executes command
 * @av: string location of shell
 * @param: string of command to exec
 * @i: number of how many child has been processed
 *
 * Return: string cmd if successful, else NULL
 */

void child(char *av, char *param, int i, char *cmd)
{
	if (_strncmp(param, "env", 3) == 0)
		env();
	else if (param[0] == '.' && param[1] == '/')
		if (location_check(param) == 0)
			_strcpy(cmd, param);
		else
			cmd[0] = '\0';
	else if (param[0] != '/')
		_strcpy(cmd, find_cmd(av, i, param));
	else
	{
		if (location_check(param) == 0)
			_strcpy(cmd, param);
		else
			cmd[0] = '\0';
	}

}
