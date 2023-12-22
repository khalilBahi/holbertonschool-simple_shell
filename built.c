#include "shell.h"
/**
 * is_built - check if the given command matches any built-in command
 * @command: char
 */
int is_built(char **command)

{
	char *built[] = {"exit", "env", NULL};
	int i;

	for (i = 0; built[i]; i++)
	{
		if (strcmp(command[0], built[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}
/**
 * handle_built - check the command is "exit" or "env"
 * @command: char
 * @status: int
 */
void handle_built(char **command, int *status)

{
	if (strcmp(command[0], "exit") == 0)
	{
		hsh_exit(command, status);
	}
	else if (strcmp(command[0], "env") == 0)
	{
		hsh_env(command, status);
	}
}
/**
 * hsh_exit - Free the command list memory
 * @command: char
 * @status: int
 */
void hsh_exit(char **command, int *status)

{
	free_2_pointer(command);
	exit(*status);
}
/**
 * hsh_env - Loop through the environment variables and free memory and reset command
 * @command: char
 * @status: int
 */
void hsh_env(char **command, int *status)

{
	int i;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
	free_2_pointer(command);
	(*status) = 0;
}
