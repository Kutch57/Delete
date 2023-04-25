#include "shell.h"

/**
 * getline_custom - reads an entire line from stream
 * @lineptr: pointer to a pointer that points to a buffer to hold the line
 * @n: pointer to a variable that holds the size of the buffer
 * @stream: stream to read from
 *
 * Return: number of characters read on success, -1 on failure
 */
ssize_t getline_custom(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[1024];
	static int buffer_pos;
	static int buffer_len;
	size_t line_len = 0;

	if (!*lineptr || !*n)
	{
		*n = 80;
		*lineptr = malloc(*n);
		if (!*lineptr)
			return (-1);
	}

	while (1)
	{
		if (buffer_pos >= buffer_len)
		{
			buffer_len = read(fileno(stream), buffer, sizeof(buffer));
			if (buffer_len <= 0)
				return (line_len ? (ssize_t)line_len : (ssize_t)buffer_len);
			buffer_pos = 0;
		}

		if (line_len >= *n - 1)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (!*lineptr)
				return (-1);
		}

		(*lineptr)[line_len++] = buffer[buffer_pos++];

		if (buffer[buffer_pos - 1] == '\n')
			break;
	}

	(*lineptr)[line_len] = '\0';
	return ((ssize_t)line_len);
}
