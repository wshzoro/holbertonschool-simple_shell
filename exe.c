#include "main.h"
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

if (access(args[0], X_OK) != 0)
_err(args);

childPid = fork();

if (childPid == -1)
{
perror("fork");
free(input);
free(args);
exit(EXIT_FAILURE);
}

if (childPid == 0)
{
execve(args[0], args, environ);
perror(args[0]);
free(args[0]);
exit(EXIT_FAILURE);
}

wait(&status);

if (WIFEXITED(status))
{
free(args);
free(input);
exit(WEXITSTATUS(status));
}
}
