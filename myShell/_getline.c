#include "main.h"
size_t _getline(char *buffer)
{
	char line[1024];
	ssize_t rbytes;
	size_t t = 0, t2 = 0, t3 = 0;
	char *new_buffer = NULL;
	size_t size = 0;

	while (t2 == 0 && (rbytes = read(STDIN_FILENO, line, 1024 -1) > 0))
	{
		if (rbytes == -1)
			return(-1);
		line[rbytes] = '\0';
		t3 = 0;
		while (line[t3] != '\0')
		{
			if (line[t3] == '\n')
				t2 = 1;
			t3++;
		}
		if (t != 0)
		{
			char *new_buffer = realloc(buffer, sizeof(char) * (size + rbytes));
			if (new_buffer == NULL)
			{
				free(buffer);
				return (-1);
			}
			buffer = new_buffer;
			strcat(buffer, line);
		}
		else
		{
			rbytes++;
			buffer = malloc(sizeof(char) * rbytes);
			if (buffer == NULL)
				return (-1);
			buffer = strcpy(buffer, line);
			buffer[rbytes] = '\0';
			size = rbytes;
			t = 1;
		}
	}
	return (size);
}
