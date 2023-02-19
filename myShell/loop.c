#include "main.h"
/**
 * loop - for continuous execution in the main process
 *@var: variable
*/
void loop(var_t *var)
{
	ssize_t r;
	char **argv, *command;
	char *w_value;
	int num;

	while (1)
	{
		write(1, "$ ", 2);
		r = _getline(var);
		argv = _strtok(var, r);
		printf("%s", argv[0]);
		check_built_in(argv);
		w_value = _which(argv[0]);
		if (w_value == NULL)
		{
			perror("Error");
			continue;
		}
		 _fork(argv, w_value);
		free(argv);
	}
}
