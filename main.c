#include "shell.h"
/**
 * main - main function
 * @ac: argument count
 * @argv: number of arguments
 * Return: Always 0
 */
int main(int ac, char **argv)
{
	char *line = NULL, **comm = NULL;
	int stat = 0;
	(void) ac;
	(void) argv;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}

		


		comm = tokenizer(line);
		if (!comm)
			continue;


		stat = _execute(comm, argv);
	}

	return (0);
}
