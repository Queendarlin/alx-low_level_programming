#include "lists.h"

/**
 * free_listint - Function to free a list
 * @head: Pointer to the first node
 */
void free_listint(listint_t *head)
{
	listint_t *currentNode;

	while (head != NULL)
	{
		currentNode = head;
		head = head->next;

		free(currentNode);
	}
}
