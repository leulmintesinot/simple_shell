#include "shell.h"
/**
 * tokenizer - show token
 * @line: of string
 * Return: command
 */
char **tokenizer(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **comm = NULL;
	int cpt = 0, i = 0;
	int j;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	if (!tmp)
		return (NULL);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(line);
		line = NULL;
		free(tmp);
		tmp = NULL;
	}
	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIM);
	}
	/*free(tmp);*/

	comm = malloc(sizeof(char *) * (cpt + 1));
	if (!comm)
	{
		free(line);
		return(NULL);
	}

	tmp = _strdup(line);
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	token = strtok(line, DELIM);
	while (token)
	{
		comm[i] = _strdup(token);
		if (!comm[i])
		{
			for (j = 0; j < i; j++)
			{
				free(comm[j]);
			}
			free(comm);
			free(tmp);
			/*free(line);*/
			return (NULL);
		}
                token = strtok(NULL, DELIM);
		i++;
	}
	comm[i] = NULL;

	free(tmp);
	free(line);
	/*comm[i] = NULL;*/
	return (comm);
}
