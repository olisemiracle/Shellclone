#include "main.h"
size_t _getline(char **buffer, size_t *n)
{
	char line[1024];
	ssize_t rbytes;
	size_t t = 0, t2 = 0, t3 = 0;

	if (buffer == NULL || n == NULL)
		return (-1);

	while (t2 == 0 && (rbytes = read(STDIN_FILENO, line, 1024 -1)))
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
			*n = *n + rbytes;
			*buffer = realloc(*buffer, *n);
			if (*buffer == NULL)
			{
				return (-1);
			}
			*buffer= strncat(*buffer, line, rbytes);
			if (*buffer == NULL)
				return(-1);
		}
		else
		{
			rbytes++;
			*buffer = malloc(sizeof(char) * rbytes);
			if (*buffer == NULL)
				return (-1);
			*buffer = strncpy(*buffer, line, rbytes);
			if (*buffer == NULL)
				return (-1);
			*n = rbytes;
			t = 1;
		}
	}
	return (*n);
}