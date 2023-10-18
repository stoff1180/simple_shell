#include "shell.h"

/**
 * print_env - Prints the environment variables
 * @cmd_line: The command line arguments
 * @status: A pointer to the status variable
 */
void print_env(char **cmd_line, int *status)
{
	int j;

	for (j = 0; environ[j]; j++)
	{
		write(STDOUT_FILENO, environ[j], _strlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_array(cmd_line);
	(*status) = 0;
}
