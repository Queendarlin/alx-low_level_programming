#include "lists.h"

/**
 *sum_dlistint - Function to return the sum of all data of a linked list
 *@head: Pointer to the head of the list
 *Return: The sum of all the data or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *ptr_current_node = head;
	int sum_data = 0;

	while (ptr_current_node != NULL)
	{
		sum_data += ptr_current_node->n;
		ptr_current_node = ptr_current_node->next;
	}

	return (sum_data);
}
