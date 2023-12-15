#include "myshell.h"

/**
 * Run_command - execute commands being parsed
 * @comd: command being executed
 * @cmd_args: arrays of arguments that follow the command
 * @command_index: index of the command
 *
 * Return: 0 on success. none
 */
int _run_command(char **comd, char **cmd_argv, int cmd_index)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = getpath(comd[0]);
	if (!full_cmd)
	{
		_perror(cmd_argv[0], comd[0], cmd_index);
		free_string_array(comd);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, comd, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			free_string_array(comd);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_string_array(comd);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
