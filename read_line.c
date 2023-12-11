#include "myshell.h"


/**
 * read_line - read input from prompt
 *
 * Return: a dynamically allocated string containing read_line.
 *       : NULL if an error occured or EOF is reached.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t charsRead;

if (issatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$", 2);
charsRead = getline(&line, &len, stdin);
if (charsRead == -1)
{
	free(line);
	perror("error reading fron input");
	return (NULL);
}
return (line);
}
