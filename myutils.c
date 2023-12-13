#include "myshell.h"

/**
 * free_string_array -free allocated mem to the tok arrsy.
 * @array: allocated mem need to be freed
 *
 * Return:0
 */
void free_string_array(char **array)
{
	int i;

	if (!array)
		return;
	for  (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array), array = NULL;
}

/**
 * _perror - print error msg to stdout.
 * @name: name of errant argument.
 * @cmd_args: command arguments
 * @command_index: error code.
 *
 * Return:0
 */
void _perror(char *name, char *cmd_args, int command_index)
{
	char *idx, msg[] = ": not found\n";

	idx = _atoi(command_idex);

	write(STDERR_FILENO, name, _stlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd_args, _strlen(cmd_args));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(idx);
}

/**
 * _atoi - converting integers to strings.
 * @n: integer
 *
 * Return: 0
 */
char *_atio(int n)
{
	char buffer[200];
	int i = 0;

	if (n == 0)


		buffer[i++] = '\0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	reverse_string(buffer, i);
	return (_strdup(buffer));
}

/**
 * reverse_string - reversing a string
 * @str: string
 * @len: length of a string
 *
 * Return: 0
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
		start[end] = tmp;
		start++;
		end--;
	}
}
