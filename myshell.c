#include "myshell.h"

/**
 * main - the entry point of simple_shell
 * @cmd_args: argument count
 * @cmd_argv: argument vector
 * Return: 0 success, -1 on error.
 */

int main(int cmd_args, char **cmd_argv)
{
	char *input_line = NULL, **comd = NULL;
	int status = 0, cmd_index = 0;
	(void)cmd_args;

	while (1)
	{
		input_line = read_line();
		if (input_line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		cmd_index++;
		comd = tokenize(input_line);
		if (!comd)
			continue;
		if (_is_builtin(comd[0]))
		_handle_builtin(comd, cmd_argv, &status, cmd_index);
		else
			status = _run_command(comd, cmd_argv, cmd_index);
	}
}

