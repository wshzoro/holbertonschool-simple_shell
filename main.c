#define _GNU_SOURCE
#include "main.h"

/**
 * spacesCheck - Check if the input only contains whitespace characters
 * @str: The input string
 * Return: 1 if only spaces or whitespace, 0 otherwise
 */
int spacesCheck(const char *str)
{
while (*str)
{
if (*str != ' ' && *str != '\t' && *str != '\n' &&
*str != '\v' && *str != '\f' && *str != '\r')
return (0);
str++;
}
return (1);
}

/**
 * main - write a UNIX command line interpreter
 * @argc: number of arguments
 * @argv: array containing program name and arguments
 * Return: Always 0
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
char *line = NULL;
size_t len = 0;
ssize_t read;
char **args = NULL;
int command_count = 0;

while (1)
{
if (isatty(STDIN_FILENO))
printf("($) ");

read = getline(&line, &len, stdin);
if (read == -1)
{
if (isatty(STDIN_FILENO))
putchar('\n');
break;
}


if (line[read - 1] == '\n')
line[read - 1] = '\0';

if (line[0] == '\0' || spacesCheck(line))
continue;

args = parse_input(line);
if (!args || args[0] == NULL)
{
ree_args(args);
continue;
}


if (handle_builtin(args))
{
free_args(args);
continue;
}

command_count++;
execute_command(args, command_count, argv[0]);
free_args(args);
}

free(line);
return (0);
}