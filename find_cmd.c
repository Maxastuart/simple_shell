#include "header.h"

/**
 * find_cmd - searches the systems PATHs for a command
 * @tcmd: a command as typed into the shell
 *
 * Return: a string on success, the directory the command is in; 0 if not found
 */
char *find_cmd(char *tcmd)
{
	int i = 0;
	char *path, *paths[256], *location;

	location = malloc(200 * sizeof(char));
	if (location == NULL)
		return (NULL);

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

	i = 0;
	while (paths[i])
	{
		strcpy(location, paths[i]); /* Copying Path[i] to *location */
		strcat(location, "/");      /* add "/" at the end */
		strcat(location, tcmd);    /* add tcmd to make full path */
		if (location_check(location) == 0)
			return (location);
		i++;
	}
	printf("command or directory not found\n");

	free(location);
	return (NULL);
}
