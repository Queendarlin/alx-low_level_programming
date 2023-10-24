#include "lists.h"

/**
 * delete_nodeint_at_index - Function to delete a node from a linked list
 * @head: Pointer to the head pointer
 * @index: Index of the node that should be deleted
 * Return: 1 o success or -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tempPtr = *head;
	unsigned int itr;
	listint_t *currentNode = NULL;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(tempPtr);
		return (1);
	}

	for (itr = 0; itr < index - 1; itr++)
	{
		if (!tempPtr || !(tempPtr->next))
			return (-1);
		tempPtr = tempPtr->next;
	}

	currentNode = tempPtr->next;
	tempPtr->next = currentNode->next;
	free(currentNode);

	return (1);
}
