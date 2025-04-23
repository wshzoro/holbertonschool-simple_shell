#include "main.h"
/**
 * path - Finds the path of the command to execute
 * @input: User input
 * Return: The
 */
char *handle_path(char *input)
{
char *token, *result;
int i = 0;

if (strchr(input, '/'))
return (strdup(input));

while (environ[i] != NULL)
{
if (strncmp(environ[i], "PATH=", 5) == 0)
{
char *path_copy = strdup(environ[i] + 5);
if (!path_copy)
return (NULL);

token = strtok(path_copy, ":");
while (token)
{
result = malloc(strlen(token) + strlen(input) + 2);
if (!result)
{
perror("Malloc failed");
free(path_copy);
return (NULL);
}

sprintf(result, "%s/%s", token, input);
if (access(result, X_OK) == 0)
{
free(path_copy);
return (result);
}

free(result);
token = strtok(NULL, ":");
}
free(path_copy);
}
i++;
}
return (NULL);
}
