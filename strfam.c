#include "main.h"

/**
* _strchr - retutns a ptr to the first character c in the string searches
*@s: string
*@c: char
*Return: pointer
*/
char *_strchr(const char *s, int c)
{
	if (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *) s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *) s);
	}
	return (NULL);
}
/**
 * _strdup - copy the string given
 * @s: pointer to the string
 * Return: pointer to the new string
 */
char *_strdup(const char *s)
{
	char *new_s;
	size_t len = _strlen(s) + 1;

	new_s = malloc(len);
	if (new_s == NULL)
	{
		free(new_s);
		return (NULL);
	}
	_memcpy(new_s, s, len);
	return (new_s);
	free(new_s);
	return (NULL);
}

/**
*_strcat - appends the src string to the dest string
*@dest: pointer to char
*@src: pointer to char
*Return: pointer to dest
*/
char *_strcat(char *dest, const char *src)
{
	char *d = dest;
	const char *s = src;

	while (*d != '\0')
	{
		d++;
	}
	while (*s != '\0')
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
	return (dest);
}

/**
 *_memcpy - copies n bytes from memory area src to memory area dest
 *@dest: char pointer
 *@src: char pointer
 *@n: amount of bytes to be copied
 *Return: ponter to dest
 */

void *_memcpy(void *dest, const void *src, size_t n)
{
	size_t j;
	char *d = (char *)dest;
	const char *s = (const char *) src;

	for (j = 0; j < n; j++)
	{
		d[j] = s[j];
	}
	return (dest);
}
