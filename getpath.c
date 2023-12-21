#include "shell.h"
char *get_path(char *command)
{
	char *env, *path, *cmd;
	struct stat st;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return strdup(command);

			return NULL;
		}
	}

	env = _getenv("PATH");
	if (env == NULL)
		return NULL;

	path = strtok(env, ":");
	while (path)
	{
		cmd = malloc(strlen(path) + strlen(command) + 2);
		if (cmd != NULL)
		{
			snprintf(cmd, strlen(path) + strlen(command) + 2, "%s/%s", path, command);
			if (stat(cmd, &st) == 0)
			{
				free(env);
				return (cmd);
			}

			free(cmd);

			path = strtok(NULL, ":");
		}
		else
		{
			free(env);
			return NULL;
		}
	}

	free(env);
	return NULL;
}
