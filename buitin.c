#include "myshell.h"

/**
 * is_builtin - check if a given command is a built-in command.
 * @comd : the command and its arguments.
 *
 * Return: 1 if the command id built-in,else 0 if not built-in
 */

int _is_builtin(char *comd)
{
	char *builtin_commands[] = { "exit", "env", "setenv", "cd", NULL};
	int idx;

	for (idx = 0; builtin_commands[idx]; idx++)
	{
		if (_strcmp(comd, builtin_commands[idx]) == 0)
			return (1);
	}
	return (0);
}
/**
 * handle_builtin - handle built-in commands.
 * @comd: built-in commands/its arguments)
 * cmd_argv: argument arrays
 * @status: command code (not used inthe code.
 * @command_index: index of command,not used in provided code it is (void)
 *
 *
 * Return: 0 meaning none.
 */
void _handle_builtin(char **comd, char **cmd_argv, int *status, int cmd_index)
{
	(void) cmd_argv;
	(void) cmd_index;

	if (_strcmp(comd[0], "exit") == 0)
		_quit_shell(comd, cmd_argv, status, cmd_index);
	else if (_strcmp(comd[0], "env") == 0)
		_display_env(comd, status);
}
/**
 * _quit_shell - Exits the shell interactive mood
 * @comd : exit command
 * @cmd_argv: argument array
 * @status: exit shell
 * command_index : void
 * @command_index: index of the command
 *
 * Return: (0) none.
 */
void _quit_shell(char **comd, char **cmd_argv, int *status, int cmd_index)
{
	int exit_val = (*status);
	char *index, msg[] = ": exit: forbiden: ";

	if (comd[1])
	{
		if (num_is_pos(comd[1]))
		{
			exit_val = custom_atoi(comd[1]);
		}
		else
		{
			index = _atoi(cmd_index);

			write(STDERR_FILENO, cmd_argv[0], _strlen(cmd_argv[0]));
			write(STDERR_FILENO, ":", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, msg, _strlen(msg));
			write(STDERR_FILENO, comd[1], _strlen(comd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			free_string_array(comd);
			(*status) = 2;
			return;
		}
	}
	free_string_array(comd);
	exit(exit_val);
}

/**
 * _display_env - prints the environment variables
 * @comd: command and arguments to print
 * status: void
 *
 *
 * Return:(0)  None.
 */
void _display_env(char **comd, int *status)
{
	int idx;

	for (idx = 0; environ[idx]; idx++)

	{
		write(STDOUT_FILENO, environ[idx], _strlen(environ[idx]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_string_array(comd);
	(*status) = 0;
}
