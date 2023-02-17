#ifndef SHELL
#define SHELL
/*prototypes for headers*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/*external variable*/
extern char **environ;

/*struct for recurrin variable for strtok*/
typedef struct list_of_variables
{
	char *str;
	int fd;
}var_t;

/*prototype for*/
static char *buffer = NULL;

/*prototype for which*/
char *_which(char *command);

/*prototype for execute*/
void execute_cmd(char **argv, char *full_path);

/*prototype for fork*/
void _fork(char **argv, char *w_value);

/*prototype for exit*/
void _my_exit(char **argv);

/* prototype for general env*/
void _env(char **argv);

/*prototype for check builtin*/
void check_built_in(char **argv);

/*prototype for getline we made*/
ssize_t _getline(var_t *var);
ssize_t enter_buffer(var_t *var, char **ptr_buffer, size_t *len);
ssize_t my_getline(var_t *var, char **ptr_buffer, size_t *length);

/*string prototypes*/
char *_strpbrk(char *s, const char *accept);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src)

/*prototype for loop*/
void loop(var_t *var);

/* strtok.c */
char **_strtok(var_t *var, ssize_t g_value);
int token_count(char *str);
char *parse(char *input, const char *delim, char **saveptr);

/*struct for buitin*/
typedef struct builtin_commands
{
	char *command;
	void (*f)();
}built_in;


#define VAR_INITIALIZE \
{NULL, 0}
#define BUFFER_SIZE 1024


#endif
