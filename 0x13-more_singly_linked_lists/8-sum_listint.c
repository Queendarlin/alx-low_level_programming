#include "lists.h"

/**
 * sum_listint - Function to return the sum of all data of a linked list
 * @head: Pointer to the first node
 * Return: The sum of the data of the node or 0 if the list is empty
 */
int sum_listint(listint_t *head)
{
	int sum_n = 0;

	while (head != NULL)
	{
		sum_n += head->n;
		head = head->next;
	}

	return (sum_n);

}
