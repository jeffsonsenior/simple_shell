#include "myshell.h"

/**
 * is_builtin - check if a given command is a built-in command.
 * @cmd_args: the command and its arguments.
 *
 * Return: 1 if the command id built-in,else 0 if not built-in
 */

int _is_builtin(char *cmd_args)
{
	char *builtin_commands[] = { "exit", "env", "setenv", "cd", NULL};
	int i;

	for (i = 0; builtin_commands[i]; i++)
	{
		if (__strcmp(cmd_args, builtin_commands[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * handle_builtin - handle built-in execution.
 * @cmd_args: built-in commands/its arguments)
 * @status: command code (not used inthe code.
 * @command_index: index of command (not used in provided code)
 *
 *
 * Return: none
 */
void _handle_builtin(char **cmd_argv, int *status, int command_index)
{
	(void)argv;
	(void)command_index;

	if (_strcmp(cmd_args[0], "exit")b == 0)
		_quit_shell(cmd_args, argv, status, comand_index);
	else if (_strcmp(cmd_args[0], "env") == 0)
		_display_env(cmd_args, status);
}
/**
 * _quit_shell - Exits the shell interactive mood
 * @cmd_args: command argument
 * @argv: argument array
 * @status: exit shell
 * @command_index: index of the command
 *
 * Return: none.
 */
void _quit_shell(char **cmd_args, char **argv, int *status, int command_index)
{
	int exit_val = (*status);
	char *qindex, msg[] = ":exit: forbiden: ";

	if (cmd_args[1])
	{
		if (num_is_pos(cmd_args[1]))
		{
			exit_val = custom_atoi(cmd_args[1]);
		}
		else
		{
			qindex = _atoi(command_index);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ":", 2);
			write(STDERR_FILENO, qindex, _strlen(qindex));
			write(STDERR_FILENO, msg, _strlen(msg));
			write(STRERR_FILENO, cmd_args[1], _strlen(cmd_args[1]));
			write(STDERR_FILENO, "\n", 1);
			free(qindex);
			free_string_array(cmd_args);
			(*status) = 2;
			return;
		}
	}
	free_string_array(cmd_args);
	exit(exit_val);
}

/**
 * _display_env - prints the environment variables
 * @cmd_args: command and arguments to print
 * status: void
 * * Return: None
 */
void _display_env(char **cmd_args, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)

	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_string_array(cmd_args);
	(*status) = 0;
}

