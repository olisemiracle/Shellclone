#include "main.h"
void execute_cmd(char **argv)
{
	char *command;
	int exec_value;
	char *full_path;

	if (argv)
	{
		command = argv[0];
		full_path = _which(command);
		if (full_path)
		{
			exec_value = execve(full_path, argv, NULL);
			if (exec_value == -1)
				perror("Error");
		}
	}
}
