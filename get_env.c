#include "myshell.h"

/**
 * getenv - gets the environment variables.
 * @var: variable to be accured
 *
 *
 * Return: always 0 on success
 */

char *_getenv(char *var)
{
	char *tmp, *key, *value, *env;
	int idx;

	for (idx = 0; environ[idx]; idx++)
	{
		tmp = _strdup(environ[idx]);
		key = strtok(tmp, "=");
		if (_strcmp(key, var) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}
