#include "myshell.h"

/**
 * getenv - gets the environment variables.
 * @var: variable to be accured
 *
 *
 *Return value of environment var, NULL if not found.
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
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
/**
 * _setenv - modify or set env var.
 * @var: environment variables
 * @val: assigned value.
 *
 * Return : 0 on success,else -1 if error occured.
 */

int _setenv(char *var, char *val)
{
	if (_getenv(var) != NULL)
	{
		if (setenv(var, val, 1) != 0)
		{
		write(STDERR_FILENO, "setenv: environment var not set\n", 41);
		return (-1);
		}
	}
	else
	{
		if (_setenv(var, val, 1) != 0)
		{
			write(STDERR_FILENO, "setenv: enviroment var not ser\n", 41);
			return (-1);
		}
	}
	return (0);
}

/**
 * _unsetenv - erase environment var.
 * @var: env variable to erase
 *
 * Return: 0 on success,else -1 if error occured.
 */
int _unsetenv(char *var)
{
	if (_getenv(var) != NULL)
	{
		if (_unsetenv(var) != 0)
		{
			write(STDERR_FILENO, "unsetenv: environment var not unset\n", 45);
			return (-1);
		}
	}
	else
	{
		write(STDERR_FILENO, "unsetenv: env var not found\n", 42);
		return (-1);
	}
	return (0);
}
