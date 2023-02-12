#include "main.h"
#include <stdio.h>

/**
 * _strlen - length of string
 * @s: variable
 * Return: length
 */

int _strlen(char *s)
{
	int value;

	for (value = 0; *s != '\0' ; ++s)
	{
		++value;
	}
	return (value);
}
#include "main.h"

/**
 * _strncpy - concatenate string
 * @dest: pointer
 * @src: variable
 * @n: variable
 *Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
		return (dest);
}
#include "main.h"

/**
 * _strcmp - compares strings
 * @s1:variable
 * @s2:pointer
 *
 * Return: answer
 */
int _strcmp(char *s1, char *s2)
{
	int a = 0, b;

	while (s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] != s2[a])
		{
			b = s1[a] - s2[a];
		}
		else
		{
			b = s1[a] - s2[a];
		}
		a++;
	}
	return (b);
}

#include "main.h"
#include <stdio.h>

/**
 *_strcpy - copies from one pointer
* @dest: point
* @src: pointer
*Return: pointer
*/

char *_strcpy(char *dest, char *src)
{
	int a, b = 0;

	for (a = 0; src[a] != '\0'; ++a)
	{
		dest[b] = src[a];
		++b;
	}
	dest[b] = '\0';
	return (dest);
}
