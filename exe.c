#include "shell.h"
/**
 * execute_command - excute the commands typed by the user
 * @commands: the commands
 * @argv: the arguments
 * Return: status value
 */
int _execute(char **command, char **argv)
{
    pid_t child;
    int status;

    child = fork();
    if (child == 0)
    {
        if (execve(command[0], command, environ) == -1)
        {
            perror(argv[0]);
            free_2_pointer(command);
            exit(100);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        free_2_pointer(command);
    }
    return (WEXITSTATUS(status));
}
