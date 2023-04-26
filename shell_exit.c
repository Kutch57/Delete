/**
 * shell_exit - Exits the shell
 * @args: Null-terminated array of arguments
 *
 * Description: Exits the shell with the provided status or 0 if none is given.
 */
void shell_exit(char **args)
{
	int status = 0;

	if (args[1])
		status = atoi(args[1]);

	free_args(args);
	exit(status);
}
