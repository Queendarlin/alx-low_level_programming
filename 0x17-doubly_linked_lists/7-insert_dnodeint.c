#include "lists.h"

/**
 *insert_dnodeint_at_index - Function to insert a new node at a given position
 *@h: Pointer to the head of the head of the list
 *@idx: The index of the list where the new node should be added
 *@n: The integer data to be stored in the new node
 *Return: The address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *ptr_current_node;
	unsigned int check_index = 0;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	ptr_current_node = *h;

	while (ptr_current_node != NULL && check_index < idx - 1)
	{
		ptr_current_node = ptr_current_node->next;
		check_index++;
	}
	if (ptr_current_node == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = ptr_current_node;
	new_node->next = ptr_current_node->next;

	if (ptr_current_node->next != NULL)
		ptr_current_node->next->prev = new_node;

	ptr_current_node->next = new_node;

	return (new_node);
}
