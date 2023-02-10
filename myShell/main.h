#ifndef SHELL
#define SHELL
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
char *_which(char *command);
void execute_cmd(char **argv, char *full_path);
char **prompt();
int _fork(char **argv, char *w_value);
void _my_exit(char *command);
#endif
