#include "main.h"
int main(int argc, char **argv)
{
	ssize_t g_value;
	size_t n = 0;
	int i = 0, token_num = 0, len;
	char *buffer = NULL, *buffer_copy = NULL, *token; 
	const char *delimiter = " \n";

	while (1)
	{
		printf("($) ");  /*prompt*/
		g_value = getline(&buffer, &n, stdin);    /*getting input*/
		if (g_value == -1)
		{
			printf("\n");
			return(-1);
		}
		
		// Allocate memory for buffer_copy and copy buffer into it
		buffer_copy = malloc(sizeof(char) * g_value);
		if (buffer_copy == NULL)
		{
			perror("hsh: Memory allocation for buffer copy failed");
			return (-1);
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

		// Get the lenth of each string, allocate memory to store the string, then copy each string into argv 
		token = strtok(buffer_copy, delimiter);
		while (token)
		{
			len = strlen(token);
			argv[i] = malloc(sizeof(char) * len);
			strcpy(argv[i], token);
			token = strtok(NULL, delimiter);
			i++;
		}
		argv[i] = NULL;
		execute_cmd(argv);

		free(buffer);
		free(buffer_copy);
		free(argv);
	}
	return (0);
}
