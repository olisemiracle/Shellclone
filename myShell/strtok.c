#include "main.h"
char **_strtok(var_t *var, ssize_t g_value)
{
	int i = 0, token_num = 0, len;
	char *buffer_copy = NULL, *token; 
	const char *delimiter = " \n";
	char **argv;
	char *buffer;

        

	if (g_value == -1)
		{
			printf("\n");
			exit(1);
		}
	buffer = var->str;
		// Allocate memory for buffer_copy and copy buffer into it 
		buffer_copy = malloc(sizeof(char) * g_value + 1);
		if (buffer_copy == NULL)
		{
			perror("hsh: Memory allocation for buffer copy failed");
			exit(1);
		}
		strcpy(buffer_copy, buffer);

		// calculate the number of tokens in buffer
		token = strtok(buffer, delimiter);

		while (token)
		{
			token_num++;
			token = strtok(NULL, delimiter);
		}
		token_num++;

		// Allocate memory for number of strings 
		argv = malloc(sizeof(char *) * token_num);
		if (argv == NULL)
		{
			printf("FRom here");
			exit(1);
		}

		//Get the lenth of eacch string, allocate memory to store the string, then copy each string into argv
		token = strtok(buffer_copy, delimiter);
		while (token)
		{
			len = strlen(token);
			argv[i] = malloc(sizeof(char) * len); 
			if (argv[i] == NULL)
			{
				exit(1);
			}
			strcpy(argv[i], token);
			token = strtok(NULL, delimiter);
			i++;
		}
		argv[i] = NULL;

		free(buffer_copy);

		return argv;	
}
