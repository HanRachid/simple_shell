#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_ARGS 100
extern char **environ;

int exeCommandLine(char *argv[MAX_ARGS]);

int _strcmp(char *s1, char *s2);

#endif
