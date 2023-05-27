#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * struct liststr - struct
 * @args: pointer
 * @numm: counter
 * @argv: name of the program
 * @env: environ
 * @number: counter
 */
typedef struct liststr
{
	char **args;
	int numm;
	char *argv;
	char **env;
	int number;
} list_t;
/**
 * struct _getline_Vars - variables used by _getline function
 * @buffer: input buffer
 * @pos: position in the buffer
 * @bytes_read: number of bytes read
 */
typedef struct _getline_Vars
{
	char buffer[BUFSIZ];
	int pos;
	ssize_t bytes_read;
} getline_Vars_t;
extern char **environ;
void _isatty(void);
void _EOF(int bytes, char *line);
void sig_handler(int signal);
int _atoi(const char *nptr);
void parse_input(char *line, char **args, int *arg_index);
int execute_command(char *line, char **args, char **argv, int numm);
char *search_path(char *line);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *s);
char *_strcpy(char *dest, char *src);
void *_realloc(void *old, ssize_t size);
char *_getenv(const char *name);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strchr(const char *s, int c);
size_t _strlen(const char *s);
int _strcmp(char const string1[], char const string2[]);
int _strncmp(const char *s1, const char *s2, size_t n);
int _putchar(char c);
void _puts(char *str);
char *_changer(unsigned int number, unsigned int numm);
void _error(list_t *list, char *string, char **argv, int numm);
int exitt(char *line, char **args, char **argv, int numm);
char *_strtok(char *str, const char *delim, char **saveptr);
size_t _strcspn(const char *s, const char *reject);
ssize_t _getline(char **ptr, size_t *n, FILE *stream);
void *_reallocd(void *ptr, unsigned int old_size, unsigned int new_size);
void provide_input(char **ptr, size_t *n, char *buff, size_t i);
void change_directory(char **args);

#endif
