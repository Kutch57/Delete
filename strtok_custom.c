#include <stddef.h>

/**
 * strtok_custom - Tokenizes a string by specified delimiters
 * @str: Input string to tokenize, NULL to continue tokenizing previous string
 * @delim: The delimiters to use for tokenization
 *
 * Return: Pointer to the next token or NULL if there are no more tokens
 */
char *strtok_custom(char *str, const char *delim)
{
	static char *static_str;

	if (str)
		static_str = str;

	if (!static_str)
		return (NULL);

	char *token_start = static_str;

	while (*static_str)
	{
		const char *delim_ptr = delim;

		while (*delim_ptr)
		{
			if (*static_str == *delim_ptr)
			{
				*static_str = '\0';
				static_str++;
				return (token_start);
			}
			delim_ptr++;
		}
		static_str++;
	}

	if (token_start != static_str)
	{
		static_str = NULL;
		return (token_start);
	}

	return (NULL);
}
