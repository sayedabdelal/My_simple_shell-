#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

#define MAX_ARGS 10
#define MAX_LINE 1024
#define MAX_ALIASES 100



void initialize_aliases();
void free_aliases();
int handle_alias_command(char **args);
char *resolve_alias(char *command);

int execute(char *command, char **arg);
char **parse_line(char *line, char **line_copy);
int shell_loop(int num_t);
void handle_signal(int sig);
char* envi(char *args);
extern char **environ;
int handle_cd_command(char *arg);




#endif 

