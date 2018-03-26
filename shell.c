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
	pid_t hmm, pid;
	char cmd[100], *param[100];
	int i = 1;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			type_prompt();
		read_cmd(param);
		pid = fork();
		if (pid < 0)
			fork_fail(pid);
		else if (pid > 0)
		{
			hmm = wait(NULL);
			if (hmm == -1)
				return (-1);
		}
		else
		{
			child(av[0], param[0], i, cmd);
			if (cmd[0] == '\0')
				write_nope(av[0], i, param[0]);
			return (execve(cmd, param, NULL));
		}
		i++;
	}
	return (-1);
}
