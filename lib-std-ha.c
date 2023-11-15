#include "shell.h"

/**
* get_len -  Calculates the number of digits in an integer.
* @n: Integer value.
* Return: Number of digits.
*/
int get_len(int n)
{
	unsigned int n1;
	int lenght = 1;

/* Adjust length for negative numbers*/

	if (n < 0)
	{
		lenght++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}

/* Count the number of digits*/

	while (n1 > 9)
	{
		lenght++;
		n1 = n1 / 10;
	}

	return (lenght);
}
/**
* aux_itoa - Converts an integer to a string.
* @n: Integer value.
* Return: Pointer to the resulting string.
*/
char *aux_itoa(int n)
{
	unsigned int n1;
	int lenght = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (lenght + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + lenght) = '\0';

/* Handle negative numbers*/

	if (n < 0)
	{
		n1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}

	lenght--;

/* Convert each digit to a character */

	do {
		*(buffer + lenght) = (n1 % 10) + '0';
		n1 = n1 / 10;
		lenght--;
	}
	while (n1 > 0)
		;
	return (buffer);
}

/**
* _atoi - Converts a string to an integer.
* @s: Input string.
* Return: Converted integer.
*/
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
	/* Break if a non-digit character is encountered after digits */
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;
		/* Handle negative sign*/

		if (*(s + count) == '-')
			pn *= -1;
		/* Count the number of digits*/

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	/* Convert each digit to an integer */
	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
