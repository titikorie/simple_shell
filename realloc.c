#include "main.h"

/**
 *_getenv - searches an env't list to find the env't variable
 *@name: - the pointer
 *Return: a pointer on success, NULL on failure
 */

char *_getenv(const char *name)
{
	char *value = NULL, **env;
	size_t len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(name, *env, len) == 0 && (*env)[len] == '=')
		{
			value = _strdup(*env + len + 1);
			if (value == NULL)
			{
				free(environ);
				free(env);
				free(value);
				perror("failed");
				return (NULL);
			}
			return (value);
		}
	}
	free(environ);
	free(env);
	free(value);
	return (NULL);
}

/**
 * _realloc - changes the size of the memory block
 * @old: pointed to the added memory
 * @size: the size of the added bytes
 * Return: ptr on success, NULL on failure
 */
void *_realloc(void *old, ssize_t size)
{
	void *new;

	if (size == 0)
	{
		free(old);
		return (NULL);
	}
	new = malloc(size);
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	if (old != NULL)
	{
		_memcpy(new, old, size);
		free(old);
	}
	return (new);
	free(new);
	return (NULL);
}
/**
 * _getline - to read inputs
 * @lineptr: points the line input
 * @n: size of the read line
 * @stream: file
 * Return:size of the read line
 */
ssize_t _getline(char **lineptr, ssize_t *n, FILE *stream)
{
	static getline_Vars_t vars;
	ssize_t total_bytes_read = 0;
	char *line = *lineptr;

	if (line == NULL || *n == 0)
	{
		*n = BUFSIZ;
		line = malloc(*n);
		if (line == NULL)
			return (-1);
		*lineptr = line;
	}
	while (1)
	{
		if (vars.pos == vars.bytes_read)
		{
			vars.bytes_read = read(fileno(stream), vars.buffer, BUFSIZ);
			vars.pos = 0;
		}
		if (vars.bytes_read == 0)
			break;
		if (vars.buffer[vars.pos] == '\n')
		{
			line[total_bytes_read] = '\0', vars.pos++, total_bytes_read++;
			break;
		}
		line[total_bytes_read] = vars.buffer[vars.pos];
		vars.pos++;
		total_bytes_read++;
		if (total_bytes_read == *n)
		{
			*n += BUFSIZ;
			line = _realloc(line, *n);
			if (line == NULL)
				return (-1);
			*lineptr = line;
		}
	}
	return ((total_bytes_read == 0 && vars.bytes_read == 0) ? -1 :
			total_bytes_read);
}
