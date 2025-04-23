#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

void _err(char *args[]);
void display_prompt(void);
void tokenize(char *input, char *args[]);
char **parse_input(char *input);
int _strcmp(const char *s1, const char *s2);
void execute_command(char **args, char *input);
void print_env(void);
char *handle_path(char *input);



#endif
