#include "header.h"

/**
 * read_cmd - reads user input for command to execute, along with parameters
 * @param: array of text strings of parameters
 *
 * Return: the number of characters read, -1 if error.
 */
int read_cmd(char **param)
{
	char *lineptr = NULL, **tok, *tmp, *token;
	ssize_t gline = 0; size_t n = 0;
	int i = 0, j = 0;

	tok = malloc(128 * sizeof(char *));
	if (tok == NULL)
		exit(EXIT_FAILURE);
	tmp = malloc(128 * sizeof(char));
	if (tmp == NULL)
	{
		free(tok);
		exit(EXIT_FAILURE);
	}
	gline = getline(&lineptr, &n, stdin);
	if (gline == -1)
	{
		free(tok); free(tmp);
		return (-1);
	}
	if (_strncmp(lineptr, "exit", 4) == 0)
		_kill(lineptr, tmp, tok);
	while (lineptr[j] != '\n')
	{
		tmp[j] = lineptr[j];
		j++;
	}
	tmp[j] = '\0';
	token = strtok(tmp, delim);
	while (token != NULL)
	{
		tok[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	for (j = 0; j < i; j++) /* THE MAGIC IS HERE: */
		param[j] = tok[j];
	param[j] = NULL;
	free(tok); free(tmp); free(lineptr);
	return (gline);
}
