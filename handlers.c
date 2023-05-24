#include "main.h"

int setenv_command(char **args, char *line) {
     
     if (args[1] == NULL || args[2] == NULL) {
          fprintf(stderr, "setenv: Invalid syntax\n");
          freee(line);
      	  return 1;
    }

    if (setenv(args[1], args[2], 1) != 0) {
          fprintf(stderr, "setenv: Failed to set environment variable\n");
          freee(line);
	  return 1;
    }
    freee(line);
    return 0;
}
int unsetenv_command(char **args, char *line) {
   
    if (args[1] == NULL) {
        fprintf(stderr, "unsetenv: Invalid syntax\n");
        freee(line);
	
	return 1;
    }

    if (unsetenv(args[1]) != 0) {
         fprintf(stderr, "unsetenv: Failed to unset environment variable\n");
         freee(line);

	 return 1;
    }
    freee(line);
    return 0;
}

int cd_command(char **args)
{
    char *path;
    char current_directory[1024];

    if (args[1] == NULL || strcmp(args[1], "~") == 0)
    {
        path = getenv("HOME");
        if (path == NULL)
        {
            fprintf(stderr, "cd: No home directory found.\n");
            return -1;
        }
    }
    else if (strcmp(args[1], "-") == 0)
    {
        path = getenv("OLDPWD");
        if (path == NULL)
        {
            fprintf(stderr, "cd: No previous directory found.\n");
            return -1;
        }
        printf("%s\n", path);
    }
    else
    {
        path = args[1];
    }

    if (chdir(path) != 0)
    {
        perror("cd");
        return -1;
    }

    if (getcwd(current_directory, sizeof(current_directory)) != NULL)
    {
        setenv("PWD", current_directory, 1);
        setenv("OLDPWD", path, 1);
    }
    else
    {
        perror("getcwd");
    }
    return -1;
}



int checkBuiltins(char **args, char *line)
{
	args = NULL;	
	line = NULL;
	if (strcmp(args[0], "setenv") == 0)
	{
		return setenv_command(args, line);
	}
	else if (strcmp(args[0], "unsetenv") == 0) {
		return unsetenv_command(args, line);
	}
	freee(line);
	return 0;

}
