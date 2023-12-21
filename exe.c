#include "shell.h"
/**
 * execute_command - excute the commands typed by the user
 * @commands: the commands
 * @argv: the arguments
 * Return: status value
 */
int _execute(char **command, char **argv, int idx)
{
	pid_t child;
	int status;
	char *cmd;

	cmd = get_path(command[0]);
	if (!cmd)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", argv[0], idx, command[0]);
		free_2_pointer(command);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(cmd, command, environ) == -1)
		{
			perror(argv[0]);
			free_2_pointer(command);
			free(cmd);
			exit(100);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_2_pointer(command);
		free(cmd);
	}
	return (WEXITSTATUS(status));
}
