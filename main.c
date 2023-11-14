#include "shell.h"

/**
* free_data - Frees memory allocated for shell data.
* @datash: Pointer to the data_shell structure.
* Return: void
*/

void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
* set_data - Initializes the data_shell structure.
* @datash: Pointer to the data_shell structure.
* @av: Command-line arguments.
* Return: void
*/

void set_data(data_shell *datash, char **av)
{
	unsigned int i;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}

	datash->_environ[i] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
* main -  Entry point for the custom shell program.
* @ac: Number of command-line arguments.
* @av: Array of command-line arguments.
* Return: Shell exit status.
*/

int main(int ac, char **av)
{
	data_shell datash;
	(void) ac; /* Unused parameter*/

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	/* Return a non-zero value in case of an error status*/
	if (datash.status < 0)
		return (255);
	return (datash.status); /* Return the shell exit status*/

}
