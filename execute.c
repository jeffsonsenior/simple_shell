#include "myshell.h"

/**
 * Run_command - execute commands being parsed
 * @input_line: the command line input
 * @cmd_args: arrays of arguments that follow the command
 * @command_index: index of the command
 *
 * Return: 0
 */
int _run_command(char **cmd_args, char **cmd_argv, int command_index)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = getpath(cmd_args[0]);
	if (!full_cmd)
	{
		_perror(cmd_argv[0], cmd_args[0], command_index);
		free_string_array(cmd_args);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, cmd_args, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			free_string_array(cmd_args);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_string_array(cmd_args);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
