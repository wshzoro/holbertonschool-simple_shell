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
if (!isspace(*str))
return (0);
str++;
}
return (1);
}

/**
 * main - write a UNIX command line interpreter
 * @argc: number of argument
 * @argv: contain the name of programm
 * Return: Always 0
 */
int main(__attribute__((unused)) int argc, char *argv[])
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
if (feof(stdin))
{
if (isatty(STDIN_FILENO))
printf("\n");
fflush(stdout);
break;
}

perror(argv[0]);
free(line);
continue;
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

execute_command(array_command, nbr_command);
free_args(array_command);
}

free(line);
return (0);
}
