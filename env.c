#include "main.h"
/**
 * print_env - print environment
 */
void print_env(void)
{
char **env = environ;

while (*env)
{
printf("%s/n", *env);
env++;
}
}
