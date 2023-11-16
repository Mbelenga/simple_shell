#include "main.h"

/**
 * main - entry point
 * Return: Always 0
 */

int main(void)
{
        ssize_t getline_output;
	char *token;

	char **args = malloc(sizeof(char *));
	
	int i = 0;

	char *input = NULL;
	size_t input_size = 0;

	while (1)
	{
		show_prompt();
		getline_output = getline(&input, &input_size, stdin);

		if (getline_output == -1)
			exit(1);
		token = strtok(input, "\n ");

		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, "\n ");
			i++;
		}
		args[i] = '\0';

		if (strcmp(args[0], "exit") == 0)
		{
			exit(1);
		}
		else if (strcmp(args[0], "/bin/ls") == 0)
		{
			execute_command(args);
		}
		else if (strcmp(args[0], "ls") == 0)
		{
			/*args[0] = "/bin/ls";*/
			execute_command(args);
		}
		else
		{
			/*execute_command(args);*/
		}
		
	free (args);
	}
	free(input);

	return (0);
}
