#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void run_shell(void);
char *read_line(void);
char **split_line(char *line);
int execute(char **args);

int shell_exit(char **args);
int shell_env(char **args);
int check_builtins(char **args);

typedef struct {
    char *name;
    int (*func)(char **);
} builtin_pair;

#endif /* S_SHELL_H */
