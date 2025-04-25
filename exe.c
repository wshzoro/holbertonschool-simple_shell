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
 * @program_name: The name of the shell executable
 */
void execute_command(char **array_command, int nbr_command, char *program_name)
{
pid_t pid;
char *command_path;

command_path = gpath(array_command[0]);
if (command_path == NULL)
{
fprintf(stderr, "%s: %d: %s: not found\n",
program_name, nbr_command, array_command[0]);
free_args(array_command);
return;
}

pid = fork();
if (pid == -1)
{
perror("fork");
free_args(array_command);
return;
}

if (pid == 0)
{
execve(command_path, array_command, environ);
perror("execve");
free_args(array_command);
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}

free_args(array_command);
}
