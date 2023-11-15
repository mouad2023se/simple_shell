#include "shell.h"

/**
* get_sigint - a signal handler for the SIGINT signal
* @sig:  interrupt signal
*/

void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
