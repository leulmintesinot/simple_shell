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
	int stat = 0, idx = 0;
	(void) ac;

	while (1)
	{
		line = read_line();
		printf("PATH: %s\n", getenv("PATH"));
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}

		idx++;
		comm = tokenizer(line);
		if (!comm)
			continue;
		if (is_builtin(comm[0]))
			handle_builtin(comm, argv, stat, idx);
		else
			stat = _execute(comm, argv, idx);

		freearray2D(comm);
	}

	return (0);
}
