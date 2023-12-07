#include "lists.h"

/**
 *add_dnodeint_end - Function to  add a new node at the end of a  list
 * @head: The pointer to the pointer of the head of the list
 * @n: The integer data to be stored in the new node
 * Return: The address of the new element or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node_end;
	dlistint_t *temp;

	if (head == NULL)
		return (NULL);

	new_node_end = malloc(sizeof(dlistint_t));

	if (new_node_end == NULL)
		return (NULL);

	new_node_end->n = n;
	new_node_end->next = NULL;

	if (*head == NULL)
	{
		new_node_end->prev = NULL;
		*head = new_node_end;
		return (new_node_end);
	}

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new_node_end;
	new_node_end->prev = temp;

	return (new_node_end);
}
