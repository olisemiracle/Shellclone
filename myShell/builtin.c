#include "main.h"
void _my_exit(char *command)
{
	if (strcmp(command, "exit") == 0)
		exit(1);
}
