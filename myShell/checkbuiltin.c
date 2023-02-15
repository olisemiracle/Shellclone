#include "main.h"
void check_built_in(char *command)
{
	int i, len = 0;
	built_in list[] = {
		{"env", _env},
		{"exit", _my_exit}
	};

	while (command[len])
		len++;
	
	for (i = 0; i < 2; i++)
	{
		if (strncmp(command, list[i].command, len) == 0)
			list[i].f();
	}
}
