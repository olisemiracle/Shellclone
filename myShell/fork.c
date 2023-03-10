#include "main.h"
/**
 * _fork - process that spaws the child and parent processes
 * @argv: name of aegumwnt
 *@w_value: variaable to store the fork process
 */
void _fork(char **argv, char *w_value)
{
	pid_t f_value;

	f_value = fork();
	if (f_value == -1)
		exit(1);
	if (f_value == 0)
	{
		execute_cmd(argv, w_value);
		perror("Error");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}
