#include "header.h"

/**
 * type_prompt - displays a prompt asking the user to input a command
 */
void type_prompt(void)
{
        char *s = "$ ";

        write(STDOUT_FILENO, s, 2);
}
