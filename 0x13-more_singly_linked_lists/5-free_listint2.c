#include "lists.h"

/**
 * free_listint2 - Function to free a list with a pointer to the head pointer
 * @head: A pointer to the head pointer
 */
void free_listint2(listint_t **head)
{
	listint_t *currentNode;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		currentNode = (*head)->next;

		free(*head);
		*head = currentNode;
	}
	*head = NULL;
}
