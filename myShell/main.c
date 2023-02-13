#include "main.h"
int main(int argc, char **argv)
{
	char *command, *w_value;
	(void)argc;

	while (1)
	{
		printf("($) ");
		argv = prompt();	
		command = argv[0];

		check_built_in(argv);
		w_value =_which(command);
		if (w_value == NULL)
		{
			perror("Error");
			continue;
		}
		 _fork(argv, w_value);

		free(argv);
	}
	return (0);
}
