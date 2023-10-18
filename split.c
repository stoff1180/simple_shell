#include "shell.h"

/**
 * split_input - Splits a string into an array of tokens.
 * @input: The input string to be split.
 * Return: An array of tokens or NULL if there's an error.
 */
char **split_input(char *input)
{
	char *token = NULL;
	char *temp = NULL;
	char **cmd = NULL;
	int i, count;

	if (!input)
		return (NULL);
	temp = _strdup(input);
	token = strtok(temp, " \t\n");
	if (token == NULL)
	{
		free(input);
		input = NULL;
		free(temp);
		temp = NULL;
		return (NULL);
	}
	for (count = 0; token != NULL; count++)
	{
		token = strtok(NULL, " \t\n");
	}
	free(temp);
	temp = NULL;
	cmd = malloc(sizeof(char *) * (count + 1));
	if (!cmd)
	{
		free(input);
		input = NULL;
		return (NULL);
	}
	token = strtok(input, " \t\n");
	for (i = 0; token != NULL; i++)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, " \t\n");
	}
	free(input);
	input = NULL;
	cmd[i] = NULL;
	return (cmd);
}
