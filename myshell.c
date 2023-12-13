#include "myshell.h"

/**
 * main - the entry point of simple_shell
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 success, -1 on error.
 */

int main(int argc, char **argv)
{
	char *input_line = NULL, **cmd_args = NULL;
	int status = 0, command_index = 0;
	(void)argc;

	while (1)
	{
		input_line = read_line();
		if (input_line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		command_index++;
		cmd_args = tokenize(input_line);
		if (!cmd_args)
			continue;
		if (_is_builtin(cmd_args[0]))
		_handle_builtin(cmd_args, argv, &status, command_index);
		else
			status = _run_command(cmd_args, argv, command_index);
	}
}

