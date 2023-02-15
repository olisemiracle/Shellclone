#include "main.h"
ssize_t _getline(var_t *var)
{
	static char *buffer;
	static size_t len = 0;
	ssize_t r;
	char **buf_store = &(var->str);
	char *p;

	r = enter_buffer(var, &buffer, &len);
	if (r == -1)
		return(-1);
	*buf_store = buffer;
	return (r);
}
ssize_t enter_buffer(var_t *var, char **ptr_buffer, size_t *len)
{
	ssize_t r;
	size_t length = 0;
	
	if (*len == 0)
	{
		*ptr_buffer = NULL;
		r = my_getline(var, ptr_buffer, &length);
	/*	if (r > 0);
		{
			if ((*ptr_buffer)[r - 1] == '\n')
			{
				(*ptr_buffer)[r - 1] = '\0';
				r--;
			}
		}*/
	}
	return (r);
}
ssize_t my_getline(var_t *var, char **ptr_buffer, size_t *length)
{
	static char buf[BUFFER_SIZE];
	static size_t len, i = 0;
	size_t len1;
	ssize_t r = 0, oldsize;
	char *str = NULL, *str2 = NULL, *string;

	str = *ptr_buffer;
	if (str == NULL && *length == 0)
		oldsize = 0;
	if (i == len)
		i = len = 0;
	r = read(var->fd, buf, BUFFER_SIZE);
	if (r >= 0)
		len = r;
	if (r == -1 || (r == 0 && len == 0))
		return (-1);
	str2 = strchr(buf + i, '\n');
	if (str2  != NULL)
		len1 = (unsigned int)(str2 - buf) + 1;
	else
		len1 = len;
	string = realloc(str, oldsize ? oldsize + len1 : len1 + 1);
	if (string == NULL)
	{
		if (str != NULL)
			free(str);
		return (-1);
	}
	if (oldsize != 0)
		strncat(string, buf + i, len1 - i);
	else
		strncpy(string, buf + i, len1 - i + 1);
	oldsize = oldsize + (len1 - i);
	i = len1;
	str = string;
	if (length != 0)
		*length = oldsize;
	*ptr_buffer = str;
	return (oldsize);
}
