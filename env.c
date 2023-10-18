#include "shell.h"

/**
 * print_env - Prints the environment variables
 * @cmd_line: The command line arguments
 * @status: A pointer to the status variable
 */
void print_env(char **cmd_line, int *status)
{
	int j = 0;
	(void)cmd_line;

	while (environ[j])
	{
		write(STDOUT_FILENO, environ[j], _strlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
	*status = 0;
}
