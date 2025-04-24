#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>

extern char **environ;

char *genv(const char *name);
void _err(char *args[]);
void execute_command(char **array_command,
int nbr_command, char *program_name);
int spacesCheck(const char *str);
int main(__attribute__((unused)) int argc, char *argv[]);
char *gpath(char *input);
void display_prompt(void);
char **get_argument(char *input);
void free_args(char **array_command);
char **get_argument(char *input);
int _strcmp(const char *s1, const char *s2);
char **parse_input(char *input);
int handle_builtin(char **args);
void print_env(void);
char *str_dup(const char *s);

#endif
