#include "shell.h"

/**
* add_rvar_node - Adds a variable node at the end of the variable list.
* @head: Pointer to the head of the variable list.
* @lvar: Length of the variable.
* @val: Pointer to the value string.
* @lval: Length of the value.
* Return: Pointer to the updated head of the variable list.
*/

r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *temp;

	/* Allocate memory for the new variable node */
	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
* free_rvar_list - Frees the memory allocated for the variable list.
* @head: Pointer to the head of the variable list.
*/
void free_rvar_list(r_var **head)
{
	r_var *temp;
	r_var *curr;

	/* Check if the list is not NULL */
	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
