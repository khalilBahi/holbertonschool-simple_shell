#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>

#define DLM " \t\n"
extern char **environ;

int _execute(char **command, char **argv, int idx);
char **tokenizer(char *line);
char *read_line(void);
void free_2_pointer(char **pointer);
char *_getenv(char *pol);
char *get_path(char *command);
int is_built(char **command);
void handle_built(char **command, int *status);
void hsh_exit(char **command, int *status);
void hsh_env(char **command, int *status);


#endif
