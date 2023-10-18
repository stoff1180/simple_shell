#include "shell.h"

/**
 * printerror - Prints an error message.
 * @name: The program name.
 * @cmd: The command that caused the error.
 * @ind: An index parameter.
 */
void printerror(char *name, char *cmd, int ind)
{
	char *index;
	char mssg[] = ": not found\n";

	index = _itoa(ind);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));
	free(index);
}

/**
 * read_input - Reads user input from stdin.
 * Return: The user input as a dynamically allocated string.
 */
char *read_input(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read_len;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	read_len = getline(&input, &len, stdin);
	if (read_len == -1)
	{
		free(input);
		return (NULL);
	}
	return (input);
}

/**
 * free_array - Frees a dynamically allocated array of strings.
 * @array: The array to free.
 */
void free_array(char **array)
{
	int i = 0;

	if (!array)
		return;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}
