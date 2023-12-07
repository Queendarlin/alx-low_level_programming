#include "lists.h"

/**
 *delete_dnodeint_at_index - Function to delete the node at an index
 *@head: The pointer to the head of the node
 *@index: The index of the node that should be deleted
 *Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *ptr_current_node, *temp;
	unsigned int check_index = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	ptr_current_node = *head;

	if (index == 0)
	{
		*head = ptr_current_node->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(ptr_current_node);
		return (1);
	}

	while (ptr_current_node != NULL && check_index < index)
	{
		ptr_current_node = ptr_current_node->next;
		check_index++;
	}

	if (ptr_current_node == NULL)
		return (-1);

	temp = ptr_current_node->prev;
	temp->next = ptr_current_node->next;

	if (ptr_current_node->next != NULL)
		ptr_current_node->next->prev = temp;

	free(ptr_current_node);

	return (1);
}
