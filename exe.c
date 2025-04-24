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
 * execute_command - Executes a command in a child process
 * @array_command: An array of command arguments
 * @nbr_command: The index of the command for error printing
 */
void execute_command(char **array_command, int nbr_command)
{
pid_t pid;
char *command_path;

pid = fork();
if (pid == -1)
{
perror("fork");
return;
}

if (pid == 0)
{
command_path = gpath(array_command[0]);
if (command_path == NULL)
{
fprintf(stderr, "./shell: %d: %s: not found\n",
nbr_command, array_command[0]);
free_args(array_command);
exit(EXIT_FAILURE);
}
execve(command_path, array_command, environ);
perror("execve");
free_args(array_command);
exit(EXIT_FAILURE);
}
else
wait(NULL);
}
