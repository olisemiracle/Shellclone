#include "main.h"
void _my_exit(char **argv)
{
	int num;

	if (argv[1] == NULL)
	{
		free(argv);
		_exit(0);
	}
	else
	{
		num = atoi(argv[1]);
		free(argv);
		_exit(num);
	}
}
