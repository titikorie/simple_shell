#include "main.h"
#define BUFSIZE 1024
/**
 * _reallocd - to reallocate memory
 * @ptr: the memory allocated
 * @old_size: allocated using malloc
 * @new_size: added memory
 * Return: pointer to the new memory allocated
 */
void *_reallocd(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}
/**
 * _getline - to read inputs
 * @ptr: points the line input
 * @n: size of the read line
 * @stream: file
 * Return:size of the read line
 */

ssize_t _getline(char **ptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t j;
	ssize_t val;
	char *buff;
	char t = 'z';

	if (j == 0)
		fflush(stream);
	else
		return (-1);
	j = 0;

	buff = malloc(sizeof(char) * BUFSIZE);
	if (buff == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && j == 0))
		{
			free(buff);
			return (-1);
		}
		if (i == 0 && j != 0)
		{
			j++;
			break;
		}
		if (j >= BUFSIZE)
			buff = _reallocd(buff, j, j + 1);
		buff[j] = t;
		j++;
	}
	buff[j] = '\0';
	provide_input(ptr, n, buff, j);
	val = j;
	if (i != 0)
		j = 0;
	return (val);
}

/**
 * provide_input - assigns the line var for get_line
 * @ptr: Buffer that store the input str
 * @buff: str that is been called to line
 * @n: size of line
 * @i: size of buffer
 */
void provide_input(char **ptr, size_t *n, char *buff, size_t i)
{

	if (*ptr == NULL)
	{
		if  (i > BUFSIZE)
			*n = i;

		else
			*n = BUFSIZE;
		*ptr = buff;
	}
	else if (*n < i)
	{
		if (i > BUFSIZE)
			*n = i;
		else
			*n = BUFSIZE;
		*ptr = buff;
	}
	else
	{
		_strcpy(*ptr, buff);
		free(buff);
	}
}
