#ifndef SHELL
#define SHELL
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
char *_which(char *command);
void execute_cmd(char **argv);
#endif
