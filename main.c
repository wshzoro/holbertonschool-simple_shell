#define _GNU_SOURCE
#include "main.h"

/**
 * spacesCheck - Check if the input only contains spaces
 * @str: The input string
 * Return: 1 if only spaces, 0 otherwise
 */
int spacesCheck(const char *str)
{
while (*str)
{
if (*str != ' ')
return (0);
str++;
}
return (1);
}

/**
 * main - Entry point of the shell
 * Return: 0 on success
 */
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t read;
char **args;

while (1)
{
if (isatty(STDIN_FILENO))
{
printf("$ ");
fflush(stdout);
}

read = getline(&line, &len, stdin);
if (read == -1)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
break;
}

if (read > 0 && line[read - 1] == '\n')
line[read - 1] = '\0';

if (line[0] == '\0' || spacesCheck(line))
continue;

if (_strcmp(line, "exit") == 0)
break;

if (_strcmp(line, "env") == 0)
{
print_env();
continue;
}

args = parse_input(line);
if (args[0] != NULL)
execute_command(args, line);

free(args);

}

free(line);

return (0);

}
