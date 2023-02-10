#include "main.h"
void execute_cmd(char **argv)
{
	char *command;
	int exec_value;

	if (argv)
	{
		command = argv[0];
		exec_value = execve(command, argv, NULL);
		if (exec_value == -1)
			perror("Error");
	}
}
