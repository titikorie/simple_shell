#include "main.h"
/**
 * change_directory - halndle cd command
 * @args: pointer to arguments
 */
void change_directory(char **args)
{
	char *dir = args[1], *oldpwd = _getenv("PWD");
	char *home = _getenv("HOME"), *pwd = malloc(1024);

	if (pwd == NULL)
	{
		perror("fatal error"), exit(127);
	}
	if (dir == NULL)
	{
		dir = home;
		if (dir == NULL)
			dir = ".";
	}
	if (_strcmp(dir, "-") == 0)
	{
		dir = oldpwd;
		if (dir == NULL)
			dir = ".";
		_puts(dir), _puts("\n");
	}
	if (chdir(dir) == -1)
		perror("cd");
	else
	{
		if (oldpwd != NULL)
		{
			if (setenv("OLDPWD", oldpwd, 1) == -1)
			{
				perror("setenv");
				exit(127);
			}
		}
		getcwd(pwd, 1024);
		if (setenv("PWD", pwd, 1) == -1)
		{
			perror("setenv");
			exit(127);
		}
	}
	free(pwd), free(home), free(dir);
}
