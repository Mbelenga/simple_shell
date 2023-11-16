#include "main.h"

/**
 * execute_env - prints the environment variables
 */

void execute_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
