#include "shell.h"
/**
 * is_builtin - check whether a command is built in
 * @comm: command to be checked
 * Return: Always 0
 */
int is_builtin(char *comm)
{
	char *words[] = {
		"cd", "echo", "exit", NULL
	};
	int i;

	for (i = 0; words[i]; i++)
	{
		if (_strcmp(comm, words[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * handle_builtin - handles the built in commands
 * 
 * Return: empty
 */
void handle_builtin(char **comm, char **argv, int stat, int idx)
{
	(void) argv;
	(void) idx;

	if (_strcmp(comm[0], "exit") == 0)
		exit_shell(comm, stat);

	else if (_strcmp(comm[0], "env") == 0)
		print_env(comm, stat);
}
/**
 * exit_shell - exit the shell
 * @comm: the command
 * @stat: exit status
 * Return: empty
 */
void exit_shell(char **comm, int stat)
{
	freearray2D(comm);
	exit(stat);
}
/**
 * print_env - print env variables
 * @comm: command
 * @stat: status
 * Return: empty
 */
void print_env(char **comm, int stat)
{
	int i;
	(void) stat;
	
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray2D(comm);
}
