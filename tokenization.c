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
	char **comd = NULL;
	int cpt = 0, idx = 0;

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

	comd = malloc(sizeof(char *) * (cpt + 1));
	if (!comd)
	{
		free(input_line), input_line = NULL;
		return (NULL);
	}
	token = strtok(input_line, DELIM);
	while (token)
	{
		comd[idx] = _strdup(token);
		token = strtok(NULL, DELIM);
		idx++;
	}
	free(input_line), input_line = NULL;
	comd[idx] = NULL;

	return (comd);
}
