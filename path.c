#include "main.h"
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
 * path - Finds the path of the command to execute
 * @input: User input
 * Return: The
 */
char *gpath(char *input)
{
char *path;
int length_input;
char *token, *tmp, *file_path;
struct stat st;

if (input == NULL)
exit(EXIT_FAILURE);

length_input = strlen(input);
if (strstr(input, "/") == NULL)
{
path = genv("PATH");
if (!path)
return (NULL);

tmp = malloc(strlen(path) + 1);
if (tmp == NULL)
perror("malloc"), exit(EXIT_FAILURE);
strcpy(tmp, path);

token = strtok(tmp, ":");
while (token)
{
file_path = malloc(length_input + strlen(token) + 2);
if (file_path == NULL)
{
				free(tmp);
perror("malloc"), exit(EXIT_FAILURE);
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

return (input);
}
