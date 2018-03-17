#include "header.h"

/**
 * type_prompt - displays a prompt asking the user to input a command
 */
void type_prompt(void)
{
	char *s = "$ ";

	write(STDOUT_FILENO, s, 2);
}

/**
 * read_cmd - reads user input for command to execute, along with parameters
 * @cmd: text string of command name
 * @param: array of text strings of parameters
 */
void read_cmd(char *cmd, char **param)
{
	char *lineptr, *tok[100];
	size_t gline, written, n = 0;
	int i = 0, j;

	gline = getline(&lineptr, &n, stdin);
	if (gline == -1)
	{
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	written = write(STDOUT_FILENO, lineptr, n);
	if (written == -1)
	{
		free(lineptr);
		exit(EXIT_FAILURE);
	}

	tok[i] = strtok(lineptr, " \n");
	i++;
	while (tok[i] != NULL)
	{
		tok[i] = strtok(NULL, " \n");
		i++;
	}

	strcpy(cmd, tok[0]); /* set command and parameters from input tokens */
	for (j = 0; j < i; j++)
		param[j] = tok[j];
	param[j] = NULL;

	free(lineptr);
}

/**
 * main - looping shell function, executing command if correctly entered
 *
 * Return: -1 on error, otherwise nothing (gives control to executed command)
 */
int main(void)
{
	pid_t hmm;
	char cmd[100], tcmd[100], *param[100];
	char *envp[] = {
		"PATH=/bin:usr/bin",
	};

	while (1)
	{
		type_prompt();
		read_cmd(tcmd, param);

		if (fork() != 0)
		{
			hmm = wait(NULL);
			if (hmm == -1)
				return (-1);
		}
		else
		{ /* CHANGE ME TO _STRCPY etc. */
			strcpy(cmd, "/bin/");
			strcat(cmd, tcmd);
			execve(cmd, param, envp);
		}
		if (cmd != *envp)
		{
			printf("Command not found\n");
		}
	}
}
