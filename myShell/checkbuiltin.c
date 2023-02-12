#include "main.h"
void check_built_in(char *command)
{
	int i, len;
	built_in list[] = {
		{"env", _env},
		{"exit", exiti}
	};

	len = strlen(command);
	
	for (i = 0; i < 2; i++)
	{
		if (strncmp(command, list[i].command, len) == 0)
			list[i].f();
	}
}
