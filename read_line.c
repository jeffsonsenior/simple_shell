#include "myshell.h"


/**
 * read_line - read input from prompt
 *
 * Return: a dynamically allocated string containing read_line.
 *       : NULL if an error occured or EOF is reached.
 */
char *read_line(void)
{
	char *input_line = NULL;
	size_t len = 0;
	ssize_t idx;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$", 2);
	idx = getline(&input_line, &len, stdin);
	if (idx == -1)
	{
		free(input_line);
		return (NULL);
	}
	return (input_line);
}
