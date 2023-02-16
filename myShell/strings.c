#include "main.h"
/**
 * _strpbrk - search for characters
 * @s: pointer to string
 * @accept: value to be found
 * Return: pointer to character
 */
char *_strpbrk(char *s, const char *accept)
{
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				return (&s[i]);
		}
	}
	return (NULL);
}
