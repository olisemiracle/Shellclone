#ifndef SHELL
#define SHELL
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
typedef struct list_of_variables
{
	char *str;
	int fd;
}var_t;
static char *buffer = NULL;
char *_which(char *command);
void execute_cmd(char **argv, char *full_path);
void _fork(char **argv, char *w_value);
void _my_exit(char **argv);
void _env(char **argv);
void check_built_in(char *command);
char **_strtok(var_t *var, ssize_t g_value);
ssize_t _getline(var_t *var);
ssize_t enter_buffer(var_t *var, char **ptr_buffer, size_t *len);
ssize_t my_getline(var_t *var, char **ptr_buffer, size_t *length);
void loop(var_t *var);
typedef struct builtin_commands
{
	char *command;
	void (*f)();
}built_in;
#define VAR_INITIALIZE \
{NULL, 0}
#define BUFFER_SIZE 1024
#endif
