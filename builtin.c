#include "shell.h"

/**
 * is_builtin - Checks if a command is a built-in command.
 * @cmd_line: The command to check.
 * Return: 1 if cmd_line is a built-in command, 0 otherwise.
 */
int is_builtin(char *cmd_line)
{
	char *builtins[] = {
		"exit", "env", "setenv", "unsetenv", "cd", NULL
	};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(cmd_line, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handle_builtin - Handles built-in commands.
 * @cmd_line: The command line arguments.
 * @argv: The program name and arguments.
 * @status: A pointer to the status variable.
 * @ind: An index parameter.
 */
void handle_builtin(char **cmd_line, char **argv, int *status, int ind)
{
	if (_strcmp(cmd_line[0], "exit") == 0)
	{
		handle_exit(cmd_line, argv, status, ind);
	}
	else if (_strcmp(cmd_line[0], "env") == 0)
	{
		print_env(cmd_line, status);
	}
}
