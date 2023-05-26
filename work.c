#include "main.h"
/**
 * main - the main function fot other prototypes
 * @numm: counter
 * @argv: arg 0
 * Return: 0
 */
int main(int numm, char **argv)
{
	char **args = NULL, *line = NULL;
	int num = 0, empty_line = 0, j, len;
	size_t i = 0;
	ssize_t bytes = 0;

	numm = 0, signal(SIGINT, sig_handler);
	while (bytes != EOF)
	{
		numm++;
		_isatty();
		bytes = _getline(&line, &i, stdin);
		_EOF(bytes, line);
		empty_line = 1;
		for (j = 0; j < bytes; j++)
		{
			if (line[j] != ' ' && line[j] != '\n')
			{
				empty_line = 0;
				break;
			}
		}
		if (empty_line)
			continue;
		len = _strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		args = malloc(sizeof(char *) * (len + 1));
		if (args == NULL)
			exit(1);
		parse_input(line, args, &num);
		if (_strncmp(line, "exit", 4) == 0)
			exitt(line, args, argv, numm);
		else if (_strncmp(line, "cd", 3) == 0)
			change_directory(args);
		else
			execute_command(line, args, argv, numm);
		free(args), args = NULL, num = 0;
	}
	free(line);
	return (0);
}
/**
 * parse_input - to devide the input using delim by strtok
 * @line: input command
 * @args: arrays of commands
 * @num: pointer to integer
 * Return: NULL
 */
void parse_input(char *line, char **args, int *num)
{
	int size = 10;
	char *saveptr, *new_args = NULL, *arg = _strtok(line, " ", &saveptr);

	while (arg != NULL)
	{
		args[*num] = arg;
		(*num)++;
		arg = _strtok(NULL, " ", &saveptr);

		if (*num >= size)
		{
			size *= 2;
			new_args = _realloc(args, sizeof(char *) * size);
			if (new_args == NULL)
			{
				perror("errno");
				exit(1);
			}
		}
	}
	if (*num == 0)
	{
		args[*num] = "";
		(*num)++;
	}
	args[*num] = NULL;
	free(new_args);
}
/**
 * execute_command - fork and excute
 * @args: arrays of command
 * @numm: counter
 * @argv: arg 0
 * @line: pointer
 * Return: none
 */
int execute_command(char *line, char **args, char **argv, int numm)
{
	int status;
	pid_t pid;
	char *path;
	list_t list;

	pid = fork();
	if (pid == -1)
	{
		perror("fork"), exit(1);
	}
	else if (pid == 0)
	{
		line = args[0];
		path = search_path(line, args, argv, numm);
		if (path == NULL)
		{
			list.args = args, list.number = numm++;
			_error(&list, ": not found\n", argv, numm++);
			free(args), free(line);
			exit(127);
		}
		args[0] = path;
		if (execve(args[0], args, environ) == -1)
		{
			list.args = args, list.number = numm++;
			free(line), free(args);
			_error(&list, "\n", argv, numm++);
			exit(127);
		}
	}
	else
		waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}
/**
 * search_path - search and find the path
 * @argv: name of program
 * @line: input command
 * @args: pointer to args
 * @numm: integer
 * Return: pointer to path
 */
char *search_path(char *line, char **args, char **argv, int numm)
{
	char *path, *path_copy = NULL, *dir, *saveptr, *full_path = NULL;

	if (_strchr(line, '/') != NULL)
		return (line);
	path = _getenv("PATH");
	path_copy = _strdup(path);
	if (path_copy == NULL)
	{
		perror("fatal error");
		exitt(line, args, argv, numm);
	}
	dir = _strtok(path_copy, ":", &saveptr);
	full_path = malloc(_strlen(dir) + _strlen(line) + 2);
	if  (full_path == NULL)
	{
		perror("fatal error");
		exitt(line, args, argv, numm);
	}
	while (dir != NULL)
	{
		if (full_path != NULL)
		{
			full_path[0] = '\0';
			_strcat(full_path, dir);
			_strcat(full_path, "/");
			_strcat(full_path, line);
		}

		if (access(full_path, X_OK) == 0)
		{
			free(path);
			free(path_copy);
			return (full_path);
		}
		dir = _strtok(NULL, ":", &saveptr);
	}
	free(full_path);
	free(path_copy);
	free(path);
	return (NULL);
}
