#include "main.h"

/**
 * tokenize_input - splits a string
 * @command: 1st argument
 * @tokens: 2nd argument
 * Return: number of tokens
 */

size_t tokenize_input(char *input, char *tokens[])
{
	int num_tokens = 0;
	char *token = strtok(input, " ");
	while (token != NULL)
	{
		tokens[num_tokens] = token;
		num_tokens++;
		token = strtok(NULL, " ");
	}
	tokens[num_tokens] = NULL;

	return (num_tokens);
}
