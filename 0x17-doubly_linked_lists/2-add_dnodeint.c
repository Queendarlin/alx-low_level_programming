#include "lists.h"

/**
 * add_dnodeint - Function to  add a new node at the beginning of a  list
 * @head: The pointer to the pointer of the head of the list
 * @n: The integer data to be stored in the new node
 * Return: The address of the new element or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node_beginning;

	if (head == NULL)
		return (NULL);

	new_node_beginning = malloc(sizeof(dlistint_t));

	if (new_node_beginning == NULL)
		return (NULL);

	new_node_beginning->n = n;
	new_node_beginning->prev = NULL;
	new_node_beginning->next = *head;

	if (*head != NULL)
		(*head)->prev = new_node_beginning;
	*head = new_node_beginning;

	return (new_node_beginning);
}
