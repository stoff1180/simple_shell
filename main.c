#include "shell.h"

/**
 * main - main function simple shell
 * @ac: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **argv)
{
	char *input = NULL;
	char **cmd_line = NULL;
	int status = 0;
	int ind = 0;
	(void)ac;

	while (1)
	{
		input = read_input();
		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (status);
		}
		ind++;
		cmd_line = split_input(input);
		if (!cmd_line)
		{
			continue;
		}
		if (is_builtin(cmd_line[0]))
		{
			handle_builtin(cmd_line, argv, &status, ind);
		}
		status = execute_input(cmd_line, argv, ind);
	}
	return (0);
}
