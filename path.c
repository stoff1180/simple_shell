#include "shell.h"

/**
 * _getenv - Gets the value of an environment variable.
 * @var: The name of the environment variable to retrieve.
 * Return: The value of the environment variable or NULL if not found.
 */
char *_getenv(char *var)
{
	char *temp, *key;
	char *val, *env;
	int j = 0;

	while (environ[j])
	{
		temp = _strdup(environ[j]);
		key = strtok(temp, " = ");
		if (_strcmp(key, var) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(temp);
			return (env);
		}
		free(temp);
		temp = NULL;
		j++;
	}
	return (NULL);
}

/**
 * _getpath - Gets the full path to a command.
 * @cmd: The name of the command.
 * Return: The full path to the command or NULL if not found.
 */
char *_getpath(char *cmd)
{
	char *path_cmd, *full_cmd, *dir;
	struct stat st;
	int i = 0;

	while (cmd[i])
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
		return (NULL);
		}
		i++;
	}
	path_cmd = _getenv("PATH");
	if (!path_cmd)
		return (NULL);
	dir = strtok(path_cmd, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, cmd);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_cmd);
				return (full_cmd);
			}
			free(full_cmd);
			full_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_cmd);
	return (NULL);
}
