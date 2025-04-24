#include "main.h"
/**
 * print_env - print the environment
 */

 void print_env(void)
 {
     char **env = environ;
 
     while (*env)
     {
         printf("%s\n", *env);
         env++;
     }
 }

 
/**
 * genv - Get the value of an environment variable
 * @name: Name of the environment variable to retrieve
 *
 * Return: Pointer to the value string of the environment variable,
 *         or NULL if the variable is not found.
 */

char *genv(const char *name)
{
char **env;
size_t len;

if (name == NULL || environ == NULL)
return (NULL);

len = strlen(name);

for (env = environ; *env != NULL; env++)
{
if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
return (*env + len + 1);
}
return (NULL);
}

