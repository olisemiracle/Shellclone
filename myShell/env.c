#include "main.h"
/**
 * _env -to initialize the environment
 * @argv: the number of arguments passed is more than the program name
 */
void _env(char **argv)
{
	int i;

	if (argv[1] == NULL)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			puts(environ[i]);
		}
	}
}
