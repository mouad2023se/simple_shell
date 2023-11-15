#include "shell.h"

/**
* cd_shell - Handles the 'cd' command in the shell.
* @datash: Data structure containing shell information.
* Return: 1 (indicating the success of the 'cd' command).
*/
int cd_shell(data_shell *datash)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = datash->args[1];

	/* Check if the argument is $HOME or ~ */

	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		ishome2 = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}

	/* If no argument is provided or if it's $HOME or ~ or --, go to home directory */

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(datash);
		return (1);
	}

	/* If the argument is "-", go to the previous directory */

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	/* If the argument is "." or "..", handle accordingly */

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	/* Otherwise, change to the specified directory */

	cd_to(datash);

	return (1);
}
