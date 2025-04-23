#include "main.h"

/**
 * tokenize - Splits the input string into tokens (arguments).
 * @input: User input string.
 * @args: Array to store the tokens.
 */
void tokenize(char *input, char *args[])
{
char *token;
unsigned int i = 0;
char *path;

token = strtok(input, " ");

while (token != NULL)
{
args[i] = token;
i++;
token = strtok(NULL, " ");
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
