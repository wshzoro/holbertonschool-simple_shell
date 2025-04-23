#include "main.h"
#include <sys/wait.h>

/**
 * _err - handles command not found errors
 * @args: arguments to check
 */
void _err(char *args[])
{
fprintf(stderr, "%s: command not found\n", args[0]);
perror("");
free(args[0]);
exit(98);
}

/**
 * execute_command - Executes the command entered by the user.
 * @args: The command arguments.
 * @input: original input string
 */
void execute_command(char **args, char *input)
{
pid_t childPid;
int status;

childPid = fork();

if (childPid == -1)
{
perror("fork");
free(input);
exit(EXIT_FAILURE);
}

if (childPid == 0)
{
if (execve(args[0], args, environ) == -1)
{
_err(args);
}
exit(EXIT_FAILURE);
}
else
{
waitpid(childPid, &status, 0);
}
if (args[0] && args[0] != NULL)
{
free(args[0]);
}
}
