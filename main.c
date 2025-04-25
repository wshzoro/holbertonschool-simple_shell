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
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
int nbr_command = 0;
char *line = NULL, **array_command = NULL;
size_t len = 0;
ssize_t read;

while (1)
{
if (isatty(STDIN_FILENO))
printf("($) ");

nbr_command++;
read = getline(&line, &len, stdin);

if (read == -1)
{
if (isatty(STDIN_FILENO))
printf("\n");
fflush(stdout);
break;
}

line[read - 1] = '\0';
if (line[0] == '\0' || spacesCheck(line))
continue;

if (strcmp(line, "exit") == 0)
break;

array_command = get_argument(line);
if (array_command[0] == NULL)
{
free_args(array_command);
continue;
}

execute_command(array_command, nbr_command, argv[0]);
free_args(array_command);
}

free(line);

return (0);
}
