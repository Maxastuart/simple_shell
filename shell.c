#include "header.h"

/**
 * main - looping shell function, executing command if correctly entered
 *
 * Return: -1 on error, otherwise nothing (gives control to executed command)
 */
int main(void)
{
	pid_t hmm;
	char cmd[100], *param[100];

	while (1)
	{
		type_prompt();
		read_cmd(param);
		if (fork() != 0)
		{
			hmm = wait(NULL);
			if (hmm == -1)
				return (-1);
		}
		else
		{
			if (_strncmp(param[0], "env", 3) == 0)
				env();
			else if (param[0][0] == '.' && param[0][1] == '/')
				if (location_check(param[0]) == 0)
					_strcpy(cmd, param[0]);
				else
					return (write_nope());
			else if (param[0][0] != '/')
				_strcpy(cmd, find_cmd(param[0]));
			else
			{
				if (location_check(param[0]) == 0)
					_strcpy(cmd, param[0]);
				else
					return (write_nope());
			}
			execve(cmd, param, NULL);
		}
	}
	return (0);
}
