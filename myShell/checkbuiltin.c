#include "main.h"
void check_built_in(char **argv)
{
	int i, len;
	built_in list[] = {
		{"env", _env},
		{"exit", _my_exit}
	};

	len = strlen(argv[0]);
	
	for (i = 0; i < 2; i++)
	{
		if (strncmp(argv[0], list[i].command, len) == 0)
			list[i].f();
	}
}
