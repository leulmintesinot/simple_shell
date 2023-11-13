#include "shell.h"
/**
 * _getpath - Handle the PATH
 * @comm - the command used
 * Return: NULL
 */
char *_getpath(char *comm)
{
	char *path_env, *full_cmd, *dir;
	struct stat st;
	int i;

	for (i = 0; comm[i]; i++)
	{
		if (comm[i] == '/')
		{
			if (stat(comm, &st) == 0)
				return (_strdup(comm));
			return (NULL);
		}
	}

	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);

	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(comm) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, comm);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);

}
