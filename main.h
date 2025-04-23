#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char environ;

void printEnv(void);
void _err(char *args[]);
void exec(char args, char input);
charpath(char input);
void display_prompt(void);
void tokenize(char *input, char *args[]);
int _strcmp(const chars1, const char s2);
char **parse_input(charinput);

#endif
