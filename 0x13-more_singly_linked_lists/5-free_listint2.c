#include "lists.h"

/**
 * free_listint2 - Function to free a list with a pointer to the head pointer
 * @head: A pointer to the head pointer
 */
void free_listint2(listint_t **head)
{
	listint_t *currentNode;

	while (*head != NULL)
	{
		currentNode = *head;
		*head = currentNode->next;

		free(currentNode);
	}
}
