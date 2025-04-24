#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>

/**
 * str_dup - Duplicates a string (custom implementation of strdup)
 * @s: The string to duplicate
 * Return: A pointer to the duplicated string, or NULL on failure
 */
char *str_dup(const char *s)
{
char *copy;
int i, len = strlen(s);

copy = malloc(len + 1);
if (!copy)
return (NULL);

for (i = 0; i < len; i++)
copy[i] = s[i];
copy[i] = '\0';

return copy;
}

/**
 * gpath - Resolve the full path of a command using the PATH environment variable
 * @input: The command entered by the user (e.g., "ls")
 *
 * Return: A pointer to a string with the full path of the command (must be freed),
 *         or NULL if the command is not found.
 */
char *gpath(char *input)
{
char *path, *token, *tmp, *file_path;
int length_input;
struct stat st;

if (input == NULL)
return (NULL);


if (strchr(input, '/'))
{
if (stat(input, &st) == 0)
return (str_dup(input));
return (NULL);
}


path = getenv("PATH");
if (!path)
return (NULL);


tmp = str_dup(path);
if (!tmp)
{
perror("malloc");
return (NULL);
}

length_input = strlen(input);
token = strtok(tmp, ":");


while (token)
{
file_path = malloc(strlen(token) + length_input + 2);
if (!file_path)
{
perror("malloc");
free(tmp);
return (NULL);
}

sprintf(file_path, "%s/%s", token, input);

if (stat(file_path, &st) == 0)
{
free(tmp);
return (file_path);
}

free(file_path);
token = strtok(NULL, ":");
}

free(tmp);
return (NULL);
}

