#include "lists.h"

/**
 * add_node_end - Function to add a new node at the end of a list
 * @head: Pointer to the first node of the list
 * @str: Pointer to the string
 *
 * Return: address of the new element, or NULL
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *add_new;
	list_t *holder = *head;
	unsigned int len_str = 0;

	while (str[len_str])
		len_str++;

	add_new = malloc(sizeof(list_t));
	if (!add_new)
		return (NULL);

	add_new->str = strdup(str);
	add_new->len = len_str;
	add_new->next = NULL;

	if (*head == NULL)
	{
		*head = add_new;
		return (add_new);
	}

	while (holder->next)
		holder = holder->next;

	holder->next = add_new;

	return (add_new);
}
