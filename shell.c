#include "header.h"

/**
 * main - looping shell function, executing command if correctly entered
 *
 * Return: -1 on error, otherwise nothing (gives control to executed command)
 */
int main(void)
{
	pid_t hmm;
	char cmd[100], *param[100], *nope = "command or directory not found\n";
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
			if (strncmp(param[0], "exit", 4) == 0)
				_kill();
			else if (strncmp(param[0], "env", 3) == 0)
				env();
			/* CHANGE ME TO _STRCPY etc. */
			else if (param[0][0] == '\0')
				exit(1);
			else if(param[0][0] == '.' && param[0][1] == '/')
				if (location_check(param[0]) == 0)
					strcpy(cmd, param[0]);
				else
				{
					printf("%s", nope);
					return(-1);
				}
			else if (param[0][0] != '/')
				strcpy(cmd, find_cmd(param[0]));
			else
			{
				if (location_check(param[0]) == 0)
					strcpy(cmd, param[0]);
				else
				{
					printf("%s", nope);
					return(-1);
				}
			}
			execve(cmd, param, NULL);
		}
	}
	return (0);
}
