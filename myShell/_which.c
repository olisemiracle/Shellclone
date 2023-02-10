#include "main.h"
/**
 * _which - takes a shell command as argument and gets the path to the command
 * @command: command to find its path
 * Return: the full path to the command's executable
 */
char *_which(char * command)
{
	char *path, *path_copy, *token;
	char *delimiter = ":";
	int com_len, dir_len;

	path = getenv("PATH");
	path_copy = malloc(sizeof(char) * strlen(path));
	strcpy(path_copy, path);

	com_len =strlen(command);
	token = strtok(path_copy, delimiter);

	while (token)
	{
		dir_len = strlen(token);
		full_path = malloc(com_len + dir_len + 2 * sizeof(char));
		strcpy(fullpath, token);
		strcat(fullpath, "/");
		strcat(fullpath, command);
		strcat(fullpath, "\0");
