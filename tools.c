#include "shell.h"
/**
 * freearrayofstring - frees array
 * @arr: array
 * Return: empty
 */
void freearray2D(char **arr)
{
	int i;
	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
	arr = NULL;
}
/**
 * printerror - prints error
 * @name: the name
 * @cmd: the command
 * @idx: the index
 * Return: empty
 */
void print_error(char *name, char *cmd, int idx)
{
	char *index, msg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(index);
}
/**
 * _itoa - integer to ASCII
 * @n: the integer
 * Return: buffer
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i++] = '\0';
	reverse_string(buffer, i);

	return (_strdup(buffer));

}
/**
 * reverse_string - reverses string
 * @str: the string
 * @len: length of the string
 * Return: empty
 */
void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
