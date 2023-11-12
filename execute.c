#include "shell.h"
/**
 * _execute - the command
 * @comm: the command
 * @argv: arg value
 *
 */
int _execute(char **comm, char **argv)
{
	pid_t child;
	int stat;

	child = fork();
	if (child == 0)
	{
		if (execve(comm[0], comm, environ) == -1)
		{
			perror(argv[0]);
			freearray2D(comm);
			exit(0);
		}

	
	}
	else
	{
		waitpid(child, &stat, 0);
		freearray2D(comm);
	}
	return (WEXITSTATUS(stat));
}
