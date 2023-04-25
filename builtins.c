#include <unistd.h>
#include "shell.h"

extern char **environ;

/**
 * shell_exit - Exit the shell
 * @args: Arguments passed to the shell
 * Return: Nothing (void)
 */
int shell_exit(char **args)
{
	(void)args;
	exit(EXIT_SUCCESS);
}

/**
 * shell_env - Print environment variables
 * @args: Arguments passed to the shell
 * Return: Always 1
 */
int shell_env(char **args)
{
	(void)args;
	for (int i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (1);
}
/**
 * check_builtins - Check for built-in commands
 * @args: Arguments passed to the shell
 * Return: 1 if a built-in command is executed, -1 otherwise
 */
int check_builtins(char **args)
{
	int i;

	builtin_pair builtins[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};
	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			return (builtins[i].func(args));
		}
	}

	return (-1);
}

