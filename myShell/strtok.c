#include "main.h"
/**
 *_strtok - tokenizes the strings
 * @var: signed int for pointer to file
 * @g_value: value of string
 * Return: returns token
 */
char **_strtok(var_t *var, ssize_t g_value)
{
	int i = 0, token_num, len;
	char *delimiter = "\n\t \r\a";
	char **argv, *buffer, *token, *buffer2;

	if (g_value == -1)
	{
		printf("\n");
		exit(1);
	}
	buffer2 = NULL;
	buffer = malloc(sizeof(char) * g_value);
	if (buffer == NULL)
		exit(1);
	strcpy(buffer, var->str);
	token_num = token_count(buffer);
	argv = malloc(sizeof(char *) * (token_num + 1));
	if (argv == NULL)
	{
		exit(1);
	}
	token = parse(buffer, delimiter, &buffer2);
	while (token)
	{
		len = strlen(token);
		argv[i] = malloc(sizeof(char) * len + 1);
		if (argv[i] == NULL)
		{
			exit(1);
		}
		strcpy(argv[i], token);
		token = parse(NULL, delimiter, &buffer2);
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
/**
 * token_count -keeps track of the token
 * @str: STRING
 * Return: string
 */
int token_count(char *str)
{
	int wc, state, i;

	i = wc = 0;
	state = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\0' || str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		{
			if (state == 1)
			{
				state = 0;
				wc++;
			}
			else
				break;
			i++;
		}
		else
		{
			state = 1;
			i++;
		}
	}
	return (wc);
}
/**
 * parse - character or variable to be parsed
 * @input: what is typed
 * @delim: what is used to separate the strings
 * @saveptr: address to address of strings
 *Return: token
 */
char *parse(char *input, const char *delim, char **saveptr)
{
	char *token;
	int i;

	i = 0;
	if (input == NULL)
		input = *saveptr;
	input += strspn(input, delim);
	if (*input == '\0')
	{
		*saveptr = input;
		return (NULL);
	}
	token = input;
	input = _strpbrk(input, delim);
	if (input == NULL)
	{
		while (token[i] != '\0')
			i++;
		*saveptr = token + i;
	}
	else
	{
		*input = '\0';
		*saveptr = input + 1;
	}
	return (token);
}
