#include "lists.h"

/**
 *get_dnodeint_at_index - Function to return the node at an index
 *@head: Pointer to the head of the list
 *@index: The index of the node to get from
 *Return: Index of the node or NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *ptr_current_node = head;
	unsigned int check_index = 0;

	while (ptr_current_node != NULL)
	{
		if (check_index == index)
			return (ptr_current_node);

		ptr_current_node = ptr_current_node->next;
		check_index++;
	}
	return (NULL);
}
