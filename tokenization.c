#include "myshell.h"

/**
 * tokenize - split a string into commands
 * @input_line: string tobe tokenized
 *
 * return: token
 */

char **tokenize(char *input_line)
{
	char *token = NULL, *tmp = NULL;
	char **cmd_args = NULL;
	int cpt = 0, command_index = 0;

	if (!input_line)
		return (NULL);

	tmp = strdup(input_line);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(input_line), input_line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;

	cmd_args = malloc(sizeof(char *) * (cpt + 1));
	if (!cmd_args)
	{
		free(input_line), input_line = NULL;
		return (NULL);
	}
	token = strtok(input_line, DELIM);
	while (token)
	{
		cmd_args[command_index] = _strdup(token);
		token = strtok(NULL, DELIM);
		command_index++;
	}
	free(input_line), input_line = NULL;
	cmd_args[command_index] = NULL;

	return (cmd_args);
}

