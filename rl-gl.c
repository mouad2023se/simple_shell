#include "shell.h"

/**
* read_line - Reads a line of input from the user.
*@i_eof: Pointer to an int that will be updated with the getline return value.
* Return: A pointer to the input string.
*/
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	/* Read a line from the standard input using getline */
	*i_eof = getline(&input, &bufsize, stdin);

	/* Return the pointer to the input string */
	return (input);
}
