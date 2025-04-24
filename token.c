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
char **args = malloc(sizeof(char *) * MAX_ARGS);
int i = 0;

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

return (args);
}
