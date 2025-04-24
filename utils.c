#include "main.h"

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if equal, or the difference between the first unmatched characters
 */
int _strcmp(const char *s1, const char *s2)
{
while (*s1 && (*s1 == *s2))
{
s1++;
s2++;
}
return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * parse_input - Splits the input line into an array of arguments
 * @input: The input line from the user
 * Return: An array of strings (tokens/arguments)
 */
char **parse_input(char *input)
{
int bufsize = 64, i = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
perror("malloc");
exit(EXIT_FAILURE);
}

token = strtok(input, " ");
while (token != NULL)
{
tokens[i++] = token;
token = strtok(NULL, " ");
}
tokens[i] = NULL;
return (tokens);
}

/**
 * handle_builtin - Check and handle built-in commands
 * @args: The argument array
 * Return: 1 if built-in was handled, 0 otherwise
 */
int handle_builtin(char **args)
{
if (args[0] == NULL)
return (1);

if (strcmp(args[0], "exit") == 0)
{
free_args(args);
exit(0);
}

if (strcmp(args[0], "env") == 0)
{
char **env;
for (env = environ; *env != NULL; env++)
{
printf("%s\n", *env);
}
free_args(args);
return (1);
}

return (0);
}
