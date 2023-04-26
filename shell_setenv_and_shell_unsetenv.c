/**
 * shell_setenv - Sets an environment variable
 * @args: Null-terminated array of arguments
 *
 * Description: Sets an environment variable with the provided key and value.
 */
void shell_setenv(char **args)
{
	if (!args[1] || !args[2])
	{
		fprintf(stderr, "setenv: missing arguments\n");
		return;
	}

	if (setenv(args[1], args[2], 1) == -1)
		perror("setenv");
}

/**
 * shell_unsetenv - Unsets an environment variable
 * @args: Null-terminated array of arguments
 *
 * Description: Unsets an environment variable with the provided key.
 */
void shell_unsetenv(char **args)
{
	if (!args[1])
	{
		fprintf(stderr, "unsetenv: missing argument\n");
		return;
	}

	if (unsetenv(args[1]) == -1)
		perror("unsetenv");
}
