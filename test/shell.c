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
	char *lineptr, **tok, *tmp, *token;
	ssize_t gline;
	size_t n = 0;
	int i = 0, j = 0;

	tok = malloc(64 * sizeof(char *));
	if (tok == NULL)
	{
		exit(EXIT_FAILURE);
	}
	tmp = malloc(64 * sizeof(char *));
	if (tmp == NULL)
	{
		free(tok);
		exit(EXIT_FAILURE);
	}
	gline = getline(&lineptr, &n, stdin);
	if (gline == -1)
	{
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	while (lineptr[j] != '\n')
	{
		tmp[j] = lineptr[j];
		j++;
	}
	tmp[j] = '\0';

	token = strtok(tmp, " \n");
	while (token != NULL)
	{
		tok[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}
	/* THE MAGIC IS HERE: */
	strcpy(cmd, tok[0]); /* set command and parameters from input tokens */
	for (j = 0; j < i; j++)
		param[j] = tok[j];
	param[j] = NULL;

	free(tok);
	free(tmp);
	free(lineptr);
}

/**
 * find_cmd - searches the systems PATHs for a command
 * @tcmd: a command as typed into the shell
 *
 * Return: a string on success, the directory the command is in; 0 if not found.
 */
char *find_cmd(char *tcmd)
{
	DIR *d;
	struct dirent *dir;
	int i = 0;
	char *path, *paths[256];

	/* finds environment variable PATHs in system */
	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = (environ[i] + 5);
			break;
		}
		i++;
	}
	i = 0;
	/* parses paths into seperate tokens */
	paths[0] = strtok(path, ":");
	while (paths[i] != NULL)
	{
		i++;
		paths[i] = strtok(NULL, ":");
	}

//	for (i = 0; paths[i]; i++)
//		printf("Path[%d]: %s\n", i, paths[i]);

	/* sees if input is in one of the PATH directories */
	i = 0; //Adriel - I reinitialize i to 0
	while (paths[i]) //reverted this to where we had it before
	{
		d = opendir(paths[i]);
		while ((dir = readdir(d)))
			if (strcmp(dir->d_name, tcmd) == 0) //I added == 0
			{
				closedir(d);
				return (paths[i]);
			}
		closedir(d);
		i++;
	}
	return (NULL);
}

/**
 * main - looping shell function, executing command if correctly entered
 *
 * Return: -1 on error, otherwise nothing (gives control to executed command)
 */
int main(void)
{
	pid_t hmm;
	char cmd[100], tcmd[100], *param[100], *path;
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
		{     /* CHANGE ME TO _STRCPY etc. */
			if (tcmd[0] != '/')
			{
				path = find_cmd(tcmd);
				strcpy(cmd, path);
				strcat(cmd, "/");
				strcat(cmd, tcmd);
				/*	else
				{
					printf("Command not found\n");
					return (-1);
					}
				*/
			}
			else
				strcpy(cmd, tcmd);
			execve(cmd, param, envp);
/*			if (cmd != *envp)
 *			{
 *				printf("Command not found\n");
 *			}
 */
		}
	}
}
