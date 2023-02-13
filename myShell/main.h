#ifndef SHELL
#define SHELL
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
static char *buffer = NULL;
char *_which(char *command);
void execute_cmd(char **argv, char *full_path);
char **prompt();
void _fork(char **argv, char *w_value);
void _my_exit(char **argv);
void _env(char **argv);
void check_built_in(char **argv);
size_t _getline(char *buffer);
typedef struct builtin_commands
{
	char *command;
	void (*f)();
}built_in;
#endif
