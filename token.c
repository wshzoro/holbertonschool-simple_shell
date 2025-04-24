#include "main.h"

#define MAX_ARGS 64

/**
 * free_args - Free each element of the argument array
 * @array_command: An array of command strings
 */
void free_args(char **array_command)
{
int i;

if (array_command == NULL)
return;

for (i = 0; array_command[i] != NULL; i++)
free(array_command[i]);

free(array_command);
}

/**
 * get_argument - Tokenize the input into an array of arguments
 * @input: Input string to tokenize
 * Return: Array of arguments
 */
char **get_argument(char *input)
{
char *token;
unsigned int i = 0;
char *path;
char **args = malloc(sizeof(char *) * MAX_ARGS);

if (args == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}

token = strtok(input, " \t\r\n\a");
while (token && i < MAX_ARGS - 1)
{
args[i] = strdup(token);
if (args[i] == NULL)
{
perror("strdup");
free_args(args);
exit(EXIT_FAILURE);
}
token = strtok(NULL, " \t\r\n\a");
i++;
}
args[i] = NULL;

if (args[0] == NULL)
_exit(0);

if (strcmp(args[0], "env") == 0)
{
print_env();
return;
}

if (strcmp(args[0], "exit") == 0 && args[1] == NULL)
{
free(args[0]);
_exit(0);
}

path = handle_path(args[0]);
if (path != NULL)
{
execve(path, args, environ);
free(path);
}
else
{
fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
_exit(127);
}
}

