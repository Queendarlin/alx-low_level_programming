#include "lists.h"

/**
 *free_dlistint - Function to free a doubly linked list
 *@head: The pointer to the head of the list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *ptr_current_node;
	dlistint_t *ptr_next_node;

	ptr_current_node = head;

	while (ptr_current_node != NULL)
	{
		ptr_next_node = ptr_current_node->next;
		free(ptr_current_node);
		ptr_current_node = ptr_next_node;
	}
}
