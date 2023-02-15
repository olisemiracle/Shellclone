#include "main.h"
void loop(var_t *var)
{
	ssize_t r;
	char **argv, *command;
	char *w_value;
	while (1)
	{
		write(1, "$ ", 2);
		r = _getline(var);
		argv = _strtok(var, r);
		command = argv[0];
		check_built_in(command);
		w_value =_which(command);
		if (w_value == NULL)
		{
			perror("Error");
			continue;
		}
		 _fork(argv, w_value);

		free(argv);
	}
}
