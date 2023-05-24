#include "main.h"
/**
 * _strtok - to separate the given inputwith space
 * @str:the string
 * @delim: space
 * @saveptr:check the code
 * Return: pointer of arrays
 */

char *_strtok(char *str, const char *delim, char **saveptr)
{
	char *token, *start;

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
		*saveptr = NULL;
		return (NULL);
	}
	start = token;
	while (*token && !strchr(delim, *token))
	{
		token++;
	}
	if (*token == '\0')
	{
		*saveptr = NULL;
	}
	else
	{
		*token = '\0';
		*saveptr = token + 1;
	}
	return (start);
}
