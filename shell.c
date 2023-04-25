#include "shell.h"
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * run_shell - Main loop of the shell
 */
void run_shell(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("#cisfun$ ");
		line = read_line();
		args = split_line(line);
		status = execute(args);

		free(line);
		free(args);
	} while (status);
}

/**
 * read_line - Read a line from the standard input
 * Return: The read line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("shell");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}

/**
 * split_line - Split a line into tokens
 * @line: The line to split
 * Return: A NULL-terminated array of pointers to tokens
 */
char **split_line(char *line)
{
	int bufsize = 64;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "shell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * execute - Execute a command
 * @args: NULL-terminated array of pointers to command and arguments
 * Return: 1 if the shell should continue running, 0 if it should terminate
 */
int execute(char **args)
{
	if (args[0] == NULL)
	{
		/* An empty command was entered */
		return (1);
	}

	pid_t pid = fork();
	int status;

	if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror("shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("shell");
	}
	else
	{
		/* Parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
