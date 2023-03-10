#include "main.h"
/**
 * execute_cmd - executes the command
 * @argv: arguments to be passed
 * @full_path: path to string
 */
void execute_cmd(char **argv, char *full_path)
{
	extern char **environ;
	int exec_value;

	if (argv)
	{
		if (full_path)
		{
			exec_value = execve(full_path, argv, environ);
			if (exec_value == -1)
				perror("Error");
		}
	}
}
