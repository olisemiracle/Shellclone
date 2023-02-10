#include "main.h"
void execute_cmd(char **argv, char *full_path)
{
	int exec_value;

	if (argv)
	{
		if (full_path)
		{
			exec_value = execve(full_path, argv, NULL);
			if (exec_value == -1)
				perror("Error");
		}
	}
}
