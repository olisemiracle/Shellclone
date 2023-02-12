#include "main.h"
void _env(char *command)
{
	extern char **environ;
	int i;

	//if (argv[1] == NULL)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			puts(environ[i]);
		}
	}
}
