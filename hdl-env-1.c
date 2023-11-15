#include "shell.h"

/**
* cmp_env_name - Compare the name of an environment variable.
* @nenv: Environment variable string.
* @name: Name to compare.
* Return: Number of characters in the common prefix, or 0 if not a match.
*/

int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
* _getenv -Get the value of an environment variable.
* @name: Name of the environment variable.
* @_environ:Array of environment variables.
* Return: Value of the environment variable, or NULL if not found.
*/

char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* Initialize ptr_env value to NULL */

	ptr_env = NULL;
	mov = 0;

	/* Iterate through the environment variables */

	for (i = 0; _environ[i]; i++)
	{
		/* Compare the name of the environment variable */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			/* If a match is found, set ptr_env to the environment variable */

			ptr_env = _environ[i];
			break;
		}
	}

	/* Return the value of the environment variable (skipping the name) */
	return (ptr_env + mov);
}

/**
*_env - Print the environment variables.
* @datash: Shell data structure.
* Return: Always returns 1.
*/

int _env(data_shell *datash)
{
	int i, j;
	/* Iterate through the environment variables */
	for (i = 0; datash->_environ[i]; i++)
	{

		/* Calculate the length of the environment variable */
		for (j = 0; datash->_environ[i][j]; j++)
			;
		/* Write the environment variable to standard output */
		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
