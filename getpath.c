#include "myshell.h"

/**
 * getpath - get the environment path to locate commands
 * @comd: the command arguments to be found
 *
 * Return: (0) - a pointer to full path of command if found,NULL if otherwise
 */

char *getpath(char *comd)
{
	char *env_path, *full_cmd, *dir;
	int idx;
	struct stat st;

	/* checking if command argument contain a '/' */
	for (idx = 0; comd[idx]; idx++)
	{
		if (comd[idx] == '/')
		{
		/*check if '/' exist */
			if (stat(comd, &st) == 0)
				return (_strdup(comd)); /* dup cmd_arg/s */
			return (NULL);
		}
	}
	/* check '/' in the path if command argument dont contain */
	env_path = getenv("PATH");
	if (!env_path)
		return (NULL);
	dir = strtok(env_path, ":");
	while (dir)
	{
		full_cmd = malloc(strlen(dir) + _strlen(comd) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, comd);
			if (stat(full_cmd, &st) == 0)
			{
				free(env_path);
				return (full_cmd);
			}
			/* free memory and reset full_cmd to NULL */
			free(full_cmd), full_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(env_path);
	return (NULL);
}
