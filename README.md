# holbertonschool-simple_shell

Simple Shell
Table of contents
Description of the project

Main files
Other files containing functions
Compilation
Examples
Requirements
Authors

Description of the project:
This is a simple UNIX shell implementation written in C. The shell provides a command-line interface for users to execute commands, similar to the standard UNIX shell. It supports basic command execution, including commands with arguments and searching for executable files in the system's PATH. The shell also handles built-in commands such as exit and env.

Main files:
main.h: Header file containing function prototypes and necessary include statements.

main.c: Main source code file implementing the basic functionality of the shell, including the main function, command execution, argument parsing, and environment variable retrieval.

Other files containing functions:

env.c:

genv: Retrieves the value of an environment variable.

Parameters:

name - The name of the environment variable.

Returns: The value associated with the environment variable or NULL if not found.

exe.c:

_err: Handles command not found errors.

Parameters:

args - The arguments to check.

execute_command: Executes a command in a child process using fork and execve.

Parameters:

array_command - The array of arguments representing the command.

nbr_command - The number of the command typed.

program_name - The name of the shell executable.

path.c:

gpath: Handles the PATH environment variable and returns the full path of an executable.

Parameters:

input - The command string.

Returns: The full path of the executable or NULL if not found.

token.c:

get_argument: Tokenizes the input into an array of arguments.

Parameters:

input - The command line string to parse.

Returns: An array of strings representing the command and its arguments.

free_args: Frees the memory allocated for an array of strings.

Parameters:

array_command - The array of strings to be freed.

Compilation:
All files were created and compiled on Ubuntu 20.04 using GCC 9.4.0 with the command:

ruby
Copier
Modifier
$ gcc -Wall -Werror -Wextra -pedantic *.c -o shell
Run the compiled program to start the shell: ./shell

Examples:
shell
Copier
Modifier
/root/holbertonschool-simple_shell# ./shell
($) ls
file1.txt  file2.txt  folder
($) lx
./shell: 1: lx: not found
($) echo Hello, World!
Hello, World!
($) /bin/echo "Goodbye, World!"
Goodbye, World!
($) ls non_existent_directory
ls: cannot access 'non_existent_directory': No such file or directory
($) exit
Requirements:
Allowed editors: vi, vim, emacs.

To follow the Betty style guide.

A README.md file (this one!).

No more than 5 functions per file.

Push the header file (main.h) containing the prototypes of all functions.

.SH NAME
simple_shell \- a simple UNIX command line interpreter

.SH SYNOPSIS
.B simple_shell

.SH DESCRIPTION
.PP
.B simple_shell
is a simple UNIX command line interpreter that allows users to execute commands,
handle paths, and work with environment variables.

.SH COMMANDS
.PP
.B simple_shell
supports the following built-in commands:

.TP
.B exit
Exit the shell.

.SH ENVIRONMENT VARIABLES
.PP
.B simple_shell
uses the following environment variable:

.TP
.B PATH
The directories to search for executable files.

.SH USAGE
.PP
Run
.B simple_shell
from the command line, and it will provide a prompt for entering commands.
It supports basic command execution and environment variable handling.

.SH EXAMPLES
.PP
.B Interactive Mode:
.RS
.B $ ./shell
.B $ ls
.B $ pwd
.B $ exit
.RE

.B Non-Interactive Mode:
.RS
.B $ echo "ls" | ./shell
.B $ echo "Hello, world!" | ./shell
.B $ echo "/bin/ls -al" | ./shell
.RE

.SH ERRORS
.PP
.B simple_shell
may display the following error messages:

.TP
.BR ./shell: <command_number>: <command>: not found
The specified command could not be found in the directories listed in the PATH environment variable.

.TP
.BR ./shell: <command>: cannot access '<file>': No such file or directory
The executable file for the specified command could not be found.

.SH SEE ALSO
.PP
.BR execve (2),
.BR fork (2),
.BR wait (2),
.BR environ (7),
.BR perror (3).

.SH AUTHOR
.PP
Authors:
BOITEL-FURLAN Julie
RACHDI Najwa
