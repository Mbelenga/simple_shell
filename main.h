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


#define MAX_INPUT_SIZE 1024
#define DELIM

extern char **environ;

void interactive(void);
void non_interactive(void);
void show_prompt(void);
char *read_input(void);
int main(void);
void execute_command(char *command);




#endif
