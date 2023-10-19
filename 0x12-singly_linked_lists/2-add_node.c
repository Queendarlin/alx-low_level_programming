#include "lists.h"

/**
 * add_node - Function to add a new node at the beginning of a list
 * @head: Pointer to the first node of the list
 * @str: Pointer to the string
 * Return: The address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *add_new;
	unsigned int len_str, index;

	for (index = 0; str[index] != '\0'; index++)
		len_str++;
	add_new = malloc(sizeof(list_t));
	if (add_new == NULL)
		return (NULL);

	add_new->str = strdup(str);
	add_new->len = len_str;
	add_new->next = (*head);

	(*head) = add_new;
	return (*head);
}
