#include "myshell.h"

/**
 * getpath - get the environment path to locate commands
 * @cmd_args: the command arguments to be found
 *
 * Return: a pointer to full path of command if found,NULL if otherwise
 */

char *getpath(char *cmd_args)
{
	char *env_path, *full_cmd, *dir;
	int command_index;
	struct stat st;

	/* checking if command argument contain a '/' */
	for (command_index = 0; cmd_args[command_index]; command_index++)
	{
		if (cmd_args[command_index] == '/')
		{
		/*check if '/' exist */
			if (stat(cmd_args, &st) == 0)
				return (_strdup(cmd_args)); /* dup cmd_arg/s */
			return (NULL);
		}
	}
	/* check '/' in the path if command argument dont contain */
	env_path = _getenv("PATH");
	if (!env_path)
		return (NULL);
	dir = strtok(env_path, ":");
	while (dir)
	{
		full_cmd = malloc(strlen(dir) + _strlen(cmd_args) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, cmd_args);
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
