#include "shell.h"

/**
 * handle_exit - Handles the exit command
 * @cmd_line: The command line arguments
 * @argv: The program name and arguments
 * @status: A pointer to the status variable
 * @ind: An index parameter
 */
void handle_exit(char **cmd_line, char **argv, int *status, int ind)
{
	int exit_value = (*status);
	char *indx;
	char mssg[] = ": exit: Illegal number: ";

	if (cmd_line[1])
	{
		if (is_posit_num(cmd_line[1]))
		{
			exit_value = _atoi(cmd_line[1]);
		}
		else
		{
			indx = _itoa(ind);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, indx, _strlen(indx));
			write(STDERR_FILENO, mssg, _strlen(mssg));
			write(STDERR_FILENO, cmd_line[1], _strlen(cmd_line[1]));
			write(STDERR_FILENO, "\n", 1);
			free(indx);
			free_array(cmd_line);
			(*status) = 2;
			return;
		}
	}
	free_array(cmd_line);
	exit(exit_value);
}
