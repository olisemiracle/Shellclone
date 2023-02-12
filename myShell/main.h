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
void exiti(char *command);
void _env(char *command);
void check_built_in(char *command);
typedef struct builtin_commands
{
	char *command;
	void (*f)();
}built_in;
#endif
