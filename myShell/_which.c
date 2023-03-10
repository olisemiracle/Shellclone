#include "main.h"
/**
 * _which - takes a shell command as argument and gets the path to the command
 * @command: command to find its path
 * Return: the full path to the command's executable
 */
char *_which(char *command)
{
	char *path, *path_copy, *token, *full_path;
	char *delimiter = ":";
	int com_len, dir_len, stat_value;
	struct stat file_info;

	path = getenv("PATH");
	if (path != NULL)
	{
		/* create a copy of path */
		path_copy = malloc(sizeof(char) * strlen(path));
		if (path_copy == NULL)
			return (NULL);
		strcpy(path_copy, path);

		com_len = strlen(command); /*length of command*/

		token = strtok(path_copy, delimiter);

		while (token)
		{
			dir_len = strlen(token);
			full_path = malloc(com_len + dir_len + 2 * sizeof(char));

			strcpy(full_path, token);
			strcat(full_path, "/");
			strcat(full_path, command);
			strcat(full_path, "\0");

			/* check if path exists*/
			stat_value = stat(full_path, &file_info);
			if (stat_value == 0)
			{
				free(path_copy);
				return (full_path);
			}
			else
			{
				free(full_path);
				token = strtok(NULL, delimiter);
			}
		}
		free(path_copy);
		/* check for command */
		stat_value = stat(command, &file_info);
		if (stat_value == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}




