#include "shell.h"

/**
 * execute_input - Executes a command with its arguments.
 * @cmd: The command and its arguments.
 * @argv: The program name and arguments.
 * @ind: An index parameter.
 * Return: The exit status of the executed command.
 */
int execute_input(char **cmd, char **argv, int ind)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getpath(cmd[0]);
	if (!full_cmd)
	{
		printerror(argv[0], cmd[0], ind);
		free_array(cmd);
		return (127);
	}
	child = fork();
	if (child == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		if (execve(full_cmd, cmd, environ) == -1)
		{
			free(full_cmd);
			full_cmd = NULL;
			free_array(cmd);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_array(cmd);
		free(full_cmd);
		full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
