/**
 * shell_cd - Changes the current directory
 * @args: Null-terminated array of arguments
 *
 * Description: Changes the current directory to the one specified in args[1].
 * If args[1] is NULL, it changes to the HOME directory.
 * If args[1] is "-", it changes to the OLDPWD directory.
 */
void shell_cd(char **args)
{
	char *dir = args[1];
	char *oldpwd;
	char *pwd;
	char buf[PATH_MAX];

	if (!dir)
	{
		dir = getenv("HOME");
	}
	else if (strcmp(dir, "-") == 0)
	{
		dir = getenv("OLDPWD");
	}

	if (!dir)
	{
		fprintf(stderr, "cd: No such directory\n");
		return;
	}

	oldpwd = getcwd(buf, sizeof(buf));
	if (chdir(dir) == -1)
	{
		perror("cd");
		return;
	}

	pwd = getcwd(buf, sizeof(buf));
	setenv("OLDPWD", oldpwd, 1);
	setenv("PWD", pwd, 1);
}
