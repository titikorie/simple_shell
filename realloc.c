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
