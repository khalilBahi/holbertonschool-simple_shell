#include "shell.h"
/**
 * tokenizer - Read commands from user
 * @line: the line of commands
 * Return: array of strings (command)
 */
char **tokenizer(char *line)
{
    char *token, *tmp = NULL, **command = NULL;
    int count = 0, i = 0;

    if (!line)
        return (NULL);
    tmp = strdup(line);
    token = strtok(tmp, DLM);
    if (token == NULL)
    {
        free(line), line = NULL;
        free(tmp), tmp = NULL;
        return (NULL);
    }

    while (token)
    {
        count++;
        token = strtok(NULL, DLM);
    }
    free(tmp), tmp = NULL;
    command = malloc(sizeof(char *) * (count + 1));
    if (!command)
    {
        free(line), line = NULL;
        return (NULL);
    }

    token = strtok(line, DLM);
    while (token)
    {
        command[i] = strdup(token);
        token = strtok(NULL, DLM);
        i++;
    }
    free(line), line = NULL;
    command[i] = NULL;
    return (command);
}