#include "shell.h"

/**
* exec_line - Exe a line of input, handling both built-in and external commands
* @datash: Pointer to the data_shell structure.
* Return: 1 if execution is successful, 0 otherwise
*/
int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	/* Check if the command is not NULL */
	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	/* If it's a built-in command, execute it */
	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}
