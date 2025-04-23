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
