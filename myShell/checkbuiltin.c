#include "main.h"
/**
 * check_built_in - checks the environment variables present
 * @argv: argument required
 */
void check_built_in(char **argv)
{
	int i, len = 0;

	built_in list[] = {
		{"env", _env},
		{"exit", _my_exit}
	};

	len = strlen(argv[0]);
	for (i = 0; i < 2; i++)
	{
		/**
		 * if (strncmp(argv[0], "exit", 4) == 0)
			list[i].f(argv, buffer);
		*/
		if (strncmp(argv[0], list[i].command, len) == 0)
			list[i].f();
	}
}
