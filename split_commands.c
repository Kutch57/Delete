#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * split_commands - splits a command line into an array of commands
 * @line: the command line
 * @delims: the delimiters to use for splitting
 *
 * Return: an array of commands
 */
char **split_commands(char *line, const char *delims)
{
	char **tokens;
	char *token;
	size_t bufsize = 64;
	size_t position = 0;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		fprintf(stderr, "split_commands: allocation error\n");
		exit(EXIT_FAILURE);
	}

	/* Replace && with & */
	char *and_operator = strstr(line, "&&");

	while (and_operator)
	{
		and_operator[1] = '&';
		and_operator = strstr(and_operator + 2, "&&");
	}

	/* Replace || with | */
	char *or_operator = strstr(line, "||");

	while (or_operator)
	{
		or_operator[1] = '|';
		or_operator = strstr(or_operator + 2, "||");
	}

	token = strtok(line, delims);
	while (token)
	{
		tokens[position++] = token;

		if (position >= bufsize)
		{
			bufsize *= 2;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "split_commands: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, delims);
	}
	tokens[position] = NULL;

	return (tokens);
}
