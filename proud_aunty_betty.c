/**
 * handle_token_allocation - Reallocate tokens if needed
 * @tokens: Array of tokens
 * @bufsize: Current buffer size
 * @position: Current position
 * Return: Reallocated tokens array if needed, otherwise original tokens array
 */
char **handle_token_allocation(char **tokens, int *bufsize, int position)
{
	if (position >= *bufsize)
	{
		*bufsize += BUFSIZE;
		tokens = realloc(tokens, *bufsize * sizeof(char *));
		if (!tokens)
		{
			fprintf(stderr, "Allocation error\n");
			exit(EXIT_FAILURE);
		}
	}

	return (tokens);
}

/**
 * split_line - Splits a line into an array of arguments
 * @line: The line to split
 * Return: NULL-terminated array of arguments
 */
char **split_line(char *line)
{
	int bufsize = BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		tokens = handle_token_allocation(tokens, &bufsize, position);

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}

