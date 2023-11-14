#ifndef MAIN_H
#define MAIN_H




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <errno.h>


#define MAX_INPUT_SIZE 1024
#define DELIM
#define MAX_ARGS 10

extern char **environ;

size_t tokenize_input(char *input, char *tokens[]);
void show_prompt(void);
char *read_input(void);
int main(void);
void execute_command(char *command);
int if_command_path(char *command);



#endif
