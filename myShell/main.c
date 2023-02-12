#include "main.h"
int main(int argc, char **argv)
{
	ssize_t g_value;
	size_t n = 0;
	int i = 0, token_num = 0;
	char *buffer = NULL, *buffer_copy = NULL, *token, *command, *w_value; 
	const char *delimiter = " \n";
	pid_t f_value;

	while (1)
	{
		argv = prompt();	
		command = argv[0];

		check_built_in(argv);
		w_value =_which(command);
		if (w_value == NULL)
		{
			perror("Error");
			continue;
		}
		 f_value = _fork(argv, w_value);
		 if (f_value == 1)
			 continue;

		free(argv);
	}
	return (0);
}
