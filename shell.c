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
void read_cmd(void) /* (char *cmd, char **param) */
{
	char *lineptr = NULL;
	size_t gline, written, n = 0;

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
	free(lineptr);
}

/**
 * main - looping shell function, executing command if correctly entered
 *
 * Return: -1 on error, otherwise nothing (gives control to executed command)
 */
int main(void)
{
	/* char cmd[100], *param[100]; */

	type_prompt();
	read_cmd(); /* (cmd, param); */
}
