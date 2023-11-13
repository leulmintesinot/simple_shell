#include "shell.h"
/**
 * _execute - the command
 * @comm: the command
 * @argv: arg value
 *
 */
int _execute(char **comm, char **argv, int idx)
{
	char *full_cmd;
	pid_t child;
	int stat;

	full_cmd = _getpath(comm[0]);
	if (!full_cmd)
	{
		print_error(argv[0], comm[0], idx);
		freearray2D(comm);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(comm[0], comm, environ) == -1)
		{
			free(full_cmd);
			full_cmd = NULL;
			freearray2D(comm);
		}

	
	}
	else
	{
		waitpid(child, &stat, 0);
		freearray2D(comm);
	}
	return (WEXITSTATUS(stat));
}
