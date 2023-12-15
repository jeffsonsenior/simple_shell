#include "myshell.h"

/**
 * free_string_array -free allocated mem to the tok arrsy.
 * @array: allocated mem need to be freed
 *
 * Return:0
 */
void free_string_array(char **array)
{
	int idx;

	if (!array)
		return;
	for  (idx = 0; array[idx]; idx++)
	{
		free(array[idx]);
		array[idx] = NULL;
	}
	free(array), array = NULL;
}

/**
 * _perror - print error msg to stdout.
 * @name: name of errant argument.
 * @comd: command
 * @cmd_index: command error code.
 *
 * Return:0
 */
void _perror(char *name, char *comd, int cmd_index)
{
	char *dx, msg[] = ": not found\n";

	dx = _atoi(cmd_index);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, dx, _strlen(dx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, comd, _strlen(comd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(dx);
}

/**
 * _atoi - converting integers to strings.
 * @n: integer
 *
 * Return: 0
 */
char *_atoi(int n)
{
	char buffer[20];
	int idx = 0;

	if (n == 0)


		buffer[idx++] = '\0';
	else
	{
		while (n > 0)
		{
			buffer[idx++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[idx] = '\0';
	reverse_string(buffer, idx);
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
		str[end] = tmp;
		start++;
		end--;
	}
}
