#include "header.h"

/**
 * find_cmd - searches the systems PATHs for a command
 * @tcmd: a command as typed into the shell
 *
 * Return: a string on success, the directory the command is in; 0 if not found
 */
char *find_cmd(char *av, int count, char *param)
{
	int i = 0;
	char *path, *paths[256], *location;

	location = malloc(200 * sizeof(char));
	if (location == NULL)
		return (NULL);

/* finds environment variable PATHs in system */
	while (environ[i])
	{
		if (_strncmp(environ[i], "PATH=", 5) == 0)
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
		_strcpy(location, paths[i]); /* Copying Path[i] to *location */
		_strcat(location, "/");      /* add "/" at the end */
		_strcat(location, param);    /* add tcmd to make full path */
		if (location_check(location) == 0)
			return (location);
		i++;
	}
	write_nope(av, count, param);

	free(location);
	return (NULL);
}
