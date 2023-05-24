#include "main.h"
/**
 * _strtok - to split it with the input
 * @str: the string to split
 * @delim: space
 * @saveptr: pointer
 * Return: pointer to char splitted
 */
char *_strtok(char *str, const char *delim, char **saveptr)
{
	char *start, *token;

	if (str != NULL)
	{
		*saveptr = str;
	}
	token = *saveptr;
	if (token == NULL)
	{
		return (NULL);
	}
	while (*token && strchr(delim, *token))
	{
		token++;
	}
	if (*token == '\0')
	{
		*saveptr = (NULL);
		return (NULL);
	}
	start = token;
	while (*token && !strchr(delim, *token))
	{
		token++;
	}
	if (*token == '\0')
	{
		*saveptr = (NULL);
	}
	else
	{
		*token = '\0';
		*saveptr = token + 1;
	}
	return (start);
}
