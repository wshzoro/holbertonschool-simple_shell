#include "main.h"

/**
 * display_prompt - Displays the shell prompt.
 */
void display_prompt(void)
{
write(STDOUT_FILENO, "($) ", 4);
}
