#include "shell.h"

/**
* get_builtin - Finds the function associated with a built-in command.
* @cmd: The built-in command name.
* Return: Pointer to the corresponding function, or NULL if not found.
*/
int (*get_builtin(char *cmd))(data_shell *)
{
	/* Array of structs representing built-in commands and their corresponding functions*/

	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int i;

	/* Loop through the array to find the matching built-in command */

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}
	/* Return the corresponding function or NULL if not found*/
	return (builtin[i].f);
}
