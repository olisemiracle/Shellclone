#include "main.h"
void _my_exit(char **argv)
{
	if (argv[1] == NULL)
	{
		free(argv);
		exit(0);
	}
}
