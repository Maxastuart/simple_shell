#include "header.h"

/**
 * main - looping shell function, executing command if correctly entered
 * @ac: argument count
 * @av: arguments in an array of strings
 *
 * Return: -1 on error, otherwise nothing (gives control to executed command)
 */
int main(int ac __attribute__((unused)), char **av)
{
	pid_t hmm;
	char cmd[100], *param[100];
	int i = 1;

	while (1)
	{
		if (isatty(STDIN_FILENO))
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
					return (write_nope(av[0], i, param[0]));
			else if (param[0][0] != '/')
				_strcpy(cmd, find_cmd(av[0], i, param[0]));
			else
			{
				if (location_check(param[0]) == 0)
					_strcpy(cmd, param[0]);
				else
					return (write_nope(av[0], i, param[0]));
			}
			return (execve(cmd, param, NULL));
		}
		i++;
	}
	return (0);
}
